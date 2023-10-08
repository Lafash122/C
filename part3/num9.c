#include <stdio.h>
#include <string.h>
#include <malloc.h>

//The function that allow to search a maximum element
int max(int x, int y) {
    if (x > y)
        return x;
    else
        return y;
}

int main() {
    char sent[80] = "";
    fgets(sent, 80, stdin);
    char seps[] = " ,:!()?.;'-\n";
    char *token, **tokens;
    int res = 0, i = 0, j, k;
    tokens = (char **) malloc(40 * sizeof(char *));
    token = strtok(sent, seps);
    while (token != NULL) {
        res = max(res, strlen(token));
        tokens[i] = token;
        token = strtok(NULL, seps);
        i++;
    }

    for (k = 0; k < i; k++) {
        for (j = 0; j < k; j++)
            if (strcmp(tokens[k], tokens[j]) == 0)
                printf("%s", tokens[k]);
    }

    free(tokens);

    return 0;
}