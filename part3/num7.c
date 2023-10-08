#include <stdio.h>
#include <string.h>

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
    char *token;
    int i = 0, res = 0;
    token = strtok(sent, seps);
    while (token != NULL) {
        res = max(res, strlen(token));
        i++;
        token = strtok(NULL, seps);
    }
    printf("%d", res);

    return 0;
}