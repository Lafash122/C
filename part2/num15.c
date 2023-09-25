#include <stdio.h>
#include <malloc.h>

//The function that allow to spiral fill the array
void spiralfill(int *arr, int len) {
    int num = 1, i, side1 = 0, side4 = 0, side2 = len - 1, side3 = len - 1;
    while (side4 <= side2) {
        for (i = side4; i <= side2; i++)
            arr[len * side1 + i] = num++;
        side1++;

        for (i = side1; i <= side3; i++)
            arr[len * i + side2] = num++;
        side2--;

        if (side1 <= side3) {
            for (i = side2; i >= side4; i--)
                arr[len * side3 + i] = num++;
            side3--;
        }

        if (side4 <= side2) {
            for (i = side3; i >= side1; i--)
                arr[len * i + side4] = num++;
            side4++;
        }
    }
}

int main() {
    int n, i;
    scanf("%d", &n);
    int *a;
    a = (int *) malloc(n * n * sizeof(int));
    spiralfill(a, n);
    for (i = 0; i < n * n; i++)
        printf("%d ", a[i]);

    free(a);

    return 0;
}