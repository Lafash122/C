#include <stdio.h>
#include <string.h>
#include <malloc.h>

#define SIZE 18

//The function that allow to define new comparison index
int newind(char *pattern, char symbol, int patternlen) {
    for (int i = patternlen - 1; i >= 0; i--)
        if (pattern[i] == symbol)
            return patternlen - i;
    return patternlen + 1;
}

int main() {
    char ptrn[SIZE] = "";
    fgets(ptrn, SIZE, stdin);

    int tlen = 0;
    char *txt = (char *) malloc(tlen * sizeof(char));
    char sym = getc(stdin);

    while (!feof(stdin)) {
        txt[tlen] = sym;
        tlen++;
        txt = (char *) realloc(txt, tlen * sizeof(char));
        sym = getc(stdin);
    }

    int plen, check;
    plen = strlen(ptrn) - 2;
    check = plen;

    while (check < tlen) {
        for (int i = check, j = plen; j >= 0; i--, j--) {
            printf("%d ", i + 1);
            if (txt[i] != ptrn[j])
                break;
        }
        check += newind(ptrn, txt[check], plen);
    }

    free(txt);
    return 0;
}
