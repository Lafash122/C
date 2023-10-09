#include <stdio.h>
#include <string.h>

//The function that allow to search a maximum element
int max(int x, int y) {
    if (x > y)
        return x;
    else
        return y;
}

//The function that allow to search a minimum element
int min(int x, int y) {
    if (x < y)
        return x;
    else
        return y;
}

int main() {
    int len, i, num = 0, cnt = 1, res = 0;
    char txt[80] = "";
    gets(txt);
    len = strlen(txt);
    for (i = 0; i < len; i++) {
        if (txt[i] == ' ')
            num++;
        if ((txt[i] == ' ') && (txt[i + 1] == ' '))
            cnt++;
        else {
            res = max(res, cnt);
            cnt = 1;
        }
    }
    printf("%d", min(res, num));

    return 0;
}
