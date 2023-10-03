#include <stdio.h>
#include <malloc.h>

int max(int x, int y) {                                        //The function that allow to search a maximum element
    if (x > y)
        return x;
    else
        return y;
}

int main() {
    int n, i, cnt = 1, len = 1;
    int *a;
    scanf("%d", &n);
    a = (int *) malloc(n * sizeof(int));
    for (i = 0; i < n; i++)
        scanf("%d", a + i);

    for (i = 0; i < n - 1; i++) {
        if ((*(a + i) % 2 == 1) && (*(a + i + 1) % 2 == 1))
            cnt++;
        else {
            len = max(len, cnt);
            cnt = 1;
        }
    }
    printf("%d", len);
    free(a);

    return 0;
}
