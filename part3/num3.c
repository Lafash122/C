#include <stdio.h>
#include <string.h>

//The function that change uppercase letters to lowercase letters
void uptolow(char *str, int len) {
    for (int i = 0; i < len; i++)
        if ('A' <= str[i] && str[i] <= 'Z')
            str[i] += 32;
}

//The function that delete repeats from string
int delrep(char *str, int *len) {
    for (int i = 0; i < *len - 1; i++)
        for (int j = i + 1; j < *len; j++)
            if (str[i] == str[j]) {
                str[j] = str[*len - 1];
                *len = *len - 1;
                j = j - 1;
            }
    return *len;
}

int main() {
    int cnt = 0, i, len;
    char txt[80] = "";
    fgets(txt, 80, stdin);
    len = strlen(txt);
    uptolow(txt, len);
    len = delrep(txt, &len);
    for (i = 0; i < len; i++)
        if ('a' <= txt[i] && txt[i] <= 'z')
            cnt++;

    printf("%d", cnt);

    return 0;
}
