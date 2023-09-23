#include <stdio.h>
#include <malloc.h>

int max(int x, int y) {                                         //The function that allow to search a maximum element
    if (x > y)
        return x;
    else
        return y;
}

int main() {
    int n, i, el;
    int *a;
    scanf("%d", &n);
    a = (int *) malloc(n * sizeof(int));
    for (i = 0; i < n; i++)
        scanf("%d", a + i);

    el = *a;
    for (i = 1; i < n; i++) {
        el = max(el, *(a + i));
    }
    printf("%d", el);
    free(a);

    return 0;
}