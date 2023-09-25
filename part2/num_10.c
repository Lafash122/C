#include <stdio.h>
#include <malloc.h>

int symmetry(int *arr, int start, int end) {                                        //The recursive function that allow to define symmetry chains in array
    if ((arr[start] == arr[end]) && (end - start > 1))
        return symmetry(arr, start + 1, end - 1);
    else if ((arr[start] == arr[end]) && (end - start == 1 || end - start == 0))
        return 1;
    else
        return 0;
}

int main() {
    int n, i, j, k;
    int *a;
    scanf("%d %d %d", &n, &i, &j);
    a = (int *) malloc(n * sizeof(int));
    for (k = 0; k < n; k++)
        scanf("%d", a + k);

    if (symmetry(a, i, j) == 1)
        printf("It is a symmetry chain");
    else
        printf("It is not a symmetry chain");
    free(a);

    return 0;
}
