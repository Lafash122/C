#include <stdio.h>
#include <string.h>
#include <malloc.h>

//The function that allow to count chars in string
int cntr(char *str, char chr) {
    int cnt = 0;
    for (int i = 0; i < strlen(str); i++)
        if (str[i] == chr)
            cnt++;
    return cnt;
}

int main() {
    char hint[80] = "";
    char word[80] = "";
    char answer[80] = "";
    char letter;
    fgets(hint, 80, stdin);
    fgets(word, 80, stdin);
    int i, j, request, len;
    len = strlen(word) - 1;
    char *hide = (char *) malloc(len * sizeof(char));
    for (i = 0; i < len; i++)
        hide[i] = '*';
    hide[len] = '\0';

    for (i = 0; i < 25; i++)
        puts("");

    printf("%s", hint);
    for (i = 0; i < 10; i++) {
        puts(hide);
        printf("Attempts left: %d. Letter or word (0 - Letter; 1 - Word)", 10 - i);
        scanf("%d\n", &request);
        if (request == 0) {
            scanf("%c", &letter);
            for (j = 0; j < len; j++)
                if (word[j] == letter)
                    hide[j] = letter;
        }
        else if (request == 1) {
            fgets(answer, 80, stdin);
            if (strcmp(answer, word) == 0) {
                puts("\nYou win!");
                return 0;
            }
            else {
                puts("\nYou lose");
                printf("The correct word is ");
                puts(word);
                return 0;
            }
        }
        if (cntr(hide, '*') == 0) {
            puts("\nYou win!");
            return 0;
        }
    }
    puts("\nYou lose");
    printf("The correct word is ");
    puts(word);
    return 0;
}
