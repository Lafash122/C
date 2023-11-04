#include <stdio.h>
#include <malloc.h>

//The function that allow to swap two elements
void swap(int *x, int *y) {
    int tmp = *x;
    *x =  *y;
    *y = tmp;
}

//The function that allow to search separator index
int sep(int *array, int start, int end) {
    int mid = array[(start + end) / 2];

    while (start <= end) {
        while (array[start] < mid)
            start++;
        while (array[end] > mid)
            end--;
        if (start >= end)
            break;
        swap(&array[start++], &array[end--]);
    }
    return end;
}

//The quicksort-function
void qsrt(int *array, int start, int end) {
    if (start < end) {
        int sp = sep(array, start, end);
        qsrt(array, start, sp);
        qsrt(array, sp + 1, end);
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int *arr = (int *) malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    qsrt(arr, 0, n - 1);

    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    free(arr);

    return 0;
}
