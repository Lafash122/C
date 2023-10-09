#include <stdio.h>
#include <string.h>
#include <malloc.h>

//The function that allow to search words without repeat's letters
int noreps(char *word) {
    int len = strlen(word);
    for (int i = 0; i <= len; i++)
        for (int j = i + 1; j <= len; j++)
            if (word[i] == word[j])
                return 0;
    return 1;
}

int main() {
    char sent[80] = "";
    fgets(sent, 80, stdin);
    char seps[] = " ,:!()?.;'-\n";
    char *token, **tokens;
    int i = 0, j;
    tokens = (char **) malloc(40 * sizeof(char *));
    token = strtok(sent, seps);
    while (token != NULL) {
        tokens[i] = token;
        token = strtok(NULL, seps);
        i++;
    }

    for (j = 1; j < i; j++)
        if (strcmp(tokens[0], tokens[j]) != 0 && noreps(tokens[j]) == 1)
            printf("%s ", tokens[j]);

    free(tokens);

    return 0;
}
