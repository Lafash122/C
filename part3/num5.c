#include <stdio.h>
#include <string.h>
#include <malloc.h>

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
    char sent1[80] = "", sent2[80] = "", sent3[80] = "";
    int *arr;
    int i, len, len1, len2, len3;
    fgets(sent1, 80, stdin);
    len = (strlen(sent1)) - 1;
    len1 = delrep(sent1, &len);
    fgets(sent2, 80, stdin);
    len = (strlen(sent2)) - 1;
    len2 = delrep(sent2, &len);
    fgets(sent3, 80, stdin);
    len = (strlen(sent3)) - 1;
    len3 = delrep(sent3, &len);
    arr = (int *) malloc(128 * sizeof(int));
    for (i = 0; i < 128; i++)
        arr[i] = 0;

    for (i = 0; i < len1; i++)
        arr[(int) sent1[i]]++;

    for (i = 0; i < len2; i++)
        arr[(int) sent2[i]]++;

    for (i = 0; i < len3; i++)
        arr[(int) sent3[i]]++;

    for (i = 0; i < 128; i++)
        if (arr[i] == 1)
            printf("%c ", i);

    return 0;
}