#include <stdio.h>
#include <string.h>
#include <malloc.h>

int main() {
    char sent1[80] = "", sent2[80] = "", sent3[80] = "";
    int *arr1, *arr2, *arr3;
    int i;
    fgets(sent1, 80, stdin);
    fgets(sent2, 80, stdin);
    fgets(sent3, 80, stdin);
    arr1 = (int *) malloc(128 * sizeof(int));
    arr2 = (int *) malloc(128 * sizeof(int));
    arr3 = (int *) malloc(128 * sizeof(int));
    for (i = 0; i < 128; i++)
        arr1[i] = 0, arr2[i] = 0, arr3[i] = 0;

    for (i = 0; i < (strlen(sent1)); i++)
        arr1[(int) sent1[i]] = 1;

    for (i = 0; i < (strlen(sent2)); i++)
        arr2[(int) sent2[i]] = 1;

    for (i = 0; i < (strlen(sent3)); i++)
        arr3[(int) sent3[i]] = 1;

    for (i = 0; i < 128; i++)
        if (arr1[i] + arr2[i] + arr3[i] == 1)
            printf("%c ", i);

    free(arr1);
    free(arr2);
    free(arr3);

    return 0;
}
