#include <stdio.h>
#include <string.h>

//The function that allow to search a minimum element
int min(int x, int y) {
    if (x < y)
        return x;
    else
        return y;
}

int main() {
    int i = 0, res = 1000;
    char sent[80] = "";
    fgets(sent, 80, stdin);
    char seps[] = " ,:!()?.;'-\n";
    char *token;
    token = strtok(sent, seps);
    while (token != NULL) {
        res = min(res, strlen(token));
        i++;
        token = strtok(NULL, seps);
    }
    if (i != 0)
        printf("%d", res);
    else
        printf("%d", i);

    return 0;
}
