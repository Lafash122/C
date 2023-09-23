#include <stdio.h>
#include <malloc.h>
#include <time.h>

void fillrand(int *arr, int len) {            //The function that randomly fill array
    srand(time(NULL));
    for (int i = 0; i < len; i++)
        *(arr + i) = rand();
}

int main() {
    int n, i;
    scanf("%d", &n);
    int *arr;
    arr = (int *) malloc(n * sizeof(int));
    fillrand(arr, n);
    for (i = 0; i < n; i++)
        printf("%d\n", *(arr + i));
    free(arr);

    return 0;
}
