#include <stdio.h>
#include <malloc.h>

//The fucntion that allow to swap two elements
void swap(int *x, int *y) {
    int tmp = *x;
    *x =  *y;
    *y = tmp;
}

//The quick sort function
void qsrt(int *array, int start, int end) {
    if (start < end) {
        int mid = array[(start + end) / 2];
        int s = start, f = end;

        while (s <= f) {
            while (array[s] < mid)
                s++;
            while (array[f] > mid)
                f--;
            if (s > f)
                break;
            swap(&array[s++], &array[f--]);
        }
        int newend = f, newstart = s;
        qsrt(array, start, newend);
        qsrt(array, newstart, end);
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
