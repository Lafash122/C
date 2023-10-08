#include <stdio.h>
#include <string.h>
#include <malloc.h>

int main() {
    char str1[80] = "", str2[80] = "", str3[80] = "";
    int *arr1, *arr2, *arr3;
    int i;
    fgets(str1, 80, stdin);
    fgets(str2, 80, stdin);
    fgets(str3, 80, stdin);
    arr1 = (int *) malloc(128 * sizeof(int));
    arr2 = (int *) malloc(128 * sizeof(int));
    arr3 = (int *) malloc(128 * sizeof(int));
    for (i = 0; i < 128; i++)
        arr1[i] = 0, arr2[i] = 0, arr3[i] = 0;

    for (i = 0; i < (strlen(str1)); i++)
        arr1[(int) str1[i]] = 1;

    for (i = 0; i < (strlen(str2)); i++)
        arr2[(int) str2[i]] = 1;

    for (i = 0; i < (strlen(str3)); i++)
        arr3[(int) str3[i]] = 1;

    for (i = 0; i < 128; i++)
        if (arr1[i] + arr2[i] + arr3[i] == 1)
            printf("%c ", i);

    free(arr1);
    free(arr2);
    free(arr3);

    return 0;
}
