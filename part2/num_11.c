#include <stdio.h>
#include <malloc.h>

void delrep(int *arr, int *len) {                                    //The function that delete repeats from array
    for (int i = 0; i < *len - 1; i++) {
        for (int j = i + 1; j < *len; j++) {
            if (*(arr + i) == *(arr + j)) {
                *(arr + j) = *(arr + *len - 1);
                *len = *len - 1;
                j = j - 1;
                arr = (int *) realloc(arr, *len * sizeof(int));

            }
        }
    }
}

int main() {
    int n, i;
    scanf("%d", &n);
    int *a;
    a = (int *) malloc(n * sizeof(int));
    for (i = 0; i < n; i++)
        scanf("%d", a + i);

    delrep(a, &n);
    for (i = 0; i < n; i++)
        printf("%d\n", *(a + i));

    free(a);

    return 0;
}
