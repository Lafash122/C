#include <stdio.h>
#include <string.h>
#include <malloc.h>

int main() {
    char sent[80] = "";
    fgets(sent, 80, stdin);
    char seps[] = " ,:!()?.;'-\n";
    char *token;
    char **tokens;
    int i = 0;
    tokens = (char **) malloc(40 * sizeof(char *));
    token = strtok(sent, seps);
    while (token != NULL) {
        tokens[i] = token;
        token = strtok(NULL, seps);
        i++;
    }

    for (i; i >= 0; i--)
        if (tokens[i] != NULL)
            printf("%s ", tokens[i]);

    free(tokens);

    return 0;
}
