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
    int res = 0, len = 0, i = 0, j, *lens;
    tokens = (char **) malloc(40 * sizeof(char *));
    lens = (int *) malloc(40 * sizeof(int));
    token = strtok(sent, seps);
    while (token != NULL) {
        res = max(res, strlen(token));
        tokens[i] = token;
        lens[i] = strlen(token);
        token = strtok(NULL, seps);
        i++;
    }

    while (len <= res) {
        for (j = 0; j < i; j++)
            if (lens[j] == len)
                printf("%s ", tokens[j]);
        len++;
    }

    free(lens);
    free(tokens);

    return 0;
}
