#include <stdio.h>
#include <string.h>
#include <malloc.h>

int main() {
    int *arr;
    int i;
    char txt[80] = "";
    fgets(txt, 80, stdin);
    arr = (int *) malloc(128 * sizeof(int));
    for (i = 0; i < 128; i++)
        arr[i] = 0;

    for (i = 0; i < strlen(txt) - 1; i++)
        arr[(int) txt[i]]++;

    i = 0;
    while (arr[i] != 3)
        i++;

    printf("%c", i);
    free(arr);

    return 0;
}