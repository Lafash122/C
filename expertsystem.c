#include <stdio.h>
#include <string.h>

#include "btree.h"

#define YES "yes"
#define NO "no"
#define MAX_QUESTION 128
#define MAX_ANSWER 4

//The function that gives the key of the next question
int newkey(char* answer, int oldkey) {
    if (!strcmp(answer, YES))
        return 2 * oldkey + 1;
    else if (!strcmp(answer, NO))
        return 2 * oldkey + 2;
    else
        return oldkey;
}

int main() {
    FILE *db = fopen("testdb.txt", "r");

    int key, curkey;
    char qstion[MAX_QUESTION], answer[MAX_ANSWER], oldq[MAX_QUESTION];
    fscanf(db, "%d", &key);
    fgets(qstion, MAX_QUESTION - 1, db);

    int qlen = strlen(qstion);
    qstion[qlen - 1] = '\0';
    puts(qstion);

    while (oldq[qlen - 2] != '.') {
        printf("Answer (yes or no):");
        gets(answer);
        printf("\n");
        key = newkey(answer, key);

        while (curkey != key) {
            fscanf(db, "%d", &curkey);
            fgets(oldq, 127, db);
            qlen = strlen(oldq);
        }
        oldq[qlen - 1] = '\0';
        puts(oldq);
    }

    printf("\nDo you agree? Answer (yes or no):");
    gets(answer);
    if (!strcmp(answer, YES)) {
        fclose(db);
        return 0;
    }
    else if (strcmp(answer, NO)) {
        printf("Syntax error");
        fclose(db);
        return 0;
    }
    fclose(db);

    FILE *olddb = fopen("testdb.txt", "r");
    FILE *newdb = fopen("newtestdb.txt", "a");

    char newans[MAX_QUESTION];
    printf("\nWhat is the correct answer?\n");
    gets(newans);

    fscanf(olddb, "%d", &curkey);
    while (curkey < key) {
        fgets(qstion, MAX_QUESTION - 1, olddb);
        fprintf(newdb, "%d", curkey);
        fputs(qstion, newdb);
        fscanf(olddb, "%d", &curkey);
    }
    char newq[MAX_QUESTION];
    printf("\nWhat the question distinguish them?\n");
    gets(newq);
    fprintf(newdb, "%d ", key);
    fputs(newq, newdb);
    fputs("\n", newdb);

    fgets(qstion, MAX_QUESTION - 1, olddb);
    fscanf(olddb, "%d", &curkey);

    while (curkey < 2 * key + 1) {
        fgets(qstion, MAX_QUESTION - 1, olddb);
        fprintf(newdb, "%d", curkey);
        fputs(qstion, newdb);
        fscanf(olddb, "%d", &curkey);
    }

    printf("\nWhat is the answer on this question? (yes or no)\n");
    gets(answer);
    int newkey;
    if (!strcmp(answer, YES)) {
        newkey = 2 * key + 1;
        fprintf(newdb, "%d ", newkey);
        fputs(newans, newdb);
        fputs("\n", newdb);
        newkey = 2 * key + 2;
        fprintf(newdb, "%d", newkey);
        fputs(oldq, newdb);
        fputs("\n", newdb);
    }
    else {
        newkey = 2 * key + 1;
        fprintf(newdb, "%d", newkey);
        fputs(oldq, newdb);
        fputs("\n", newdb);
        newkey = 2 * key + 2;
        fprintf(newdb, "%d ", newkey);
        fputs(newans, newdb);
        fputs("\n", newdb);
    }

    while (!feof(olddb)) {
        fgets(qstion, MAX_QUESTION - 1, olddb);
        fprintf(newdb, "%d", curkey);
        fputs(qstion, newdb);
        fscanf(olddb, "%d", &curkey);
    }

    fclose(newdb);
    fclose(olddb);
    rename("newtestdb.txt", "tmp.txt");
    rename("testdb.txt", "newtestdb.txt");
    rename("tmp.txt", "testdb.txt");
    remove("newtestdb.txt");

    return 0;
}