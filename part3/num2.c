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
    int len, i, cnt = 1, res = 0;
    char txt[80] = "";
    fgets(txt, 80, stdin);
    len = strlen(txt);
    for (i = 0; i < len; i++) {
        if (txt[i] == txt[i + 1])
            cnt++;
        else {
            res = max(res, cnt);
            cnt = 1;
        }
    }
    printf("%d", res);

    return 0;
}
