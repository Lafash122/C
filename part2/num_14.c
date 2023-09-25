#include <stdio.h>
#include <malloc.h>

void spiralfill(int **arr, int len) {                //The function that allow to spiral fill the array
    int line, num = 1, i;
    for (line = 0; line < len / 2; line++) {
        for (i = line; i < len - line; i++)
            arr[line][i] = num++;

        for (i = line + 1; i < len - line; i++)
            arr[i][len - line - 1] = num++;

        for (i = len - line - 2; i >= line; i--)
            arr[len - line - 1][i] = num++;

        for (i = len - line - 2; i > line; i--)
            arr[i][line] = num++;
    }
    if (len % 2 == 1)
        arr[len / 2][len / 2] = len * len;
}

int main() {
    int n, i, j;
    scanf("%d", &n);
    int **a;
    a = (int **) malloc(n * sizeof(int *));
    for (i = 0; i < n; i++)
        a[i] = (int *) malloc(n * sizeof(int));

    spiralfill(a, n);
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++)
            printf("%d\t", a[i][j]);
        printf("\n");
    }
    free(a);

    return 0;
}
