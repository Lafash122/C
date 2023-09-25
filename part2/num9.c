#include <stdio.h>
#include <malloc.h>

int maxel(int *arr, int len, int ind, int res) {        //The recursive function that allow to search a maximum element
    if (ind == len)
        return res;
    if (*(arr + ind) > res)
        return maxel(arr, len, ind + 1, *(arr + ind));
    else
        return maxel(arr, len, ind + 1, res);
}

int main() {
    int n, i, el;
    int *a;
    scanf("%d", &n);
    a = (int *) malloc(n * sizeof(int));
    for (i = 0; i < n; i++)
        scanf("%d", a + i);

    printf("%d", maxel(a, n, 0, *a));
    free(a);

    return 0;
}
