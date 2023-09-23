#include <stdio.h>
#include <malloc.h>
#include <math.h>

int square(int x) {                                //The function that allow to search a square number
    if (pow((int) sqrt(x), 2) == x)
        return 1;
    else
        return 0;
}

int main() {
    int cnt = 0, n, i;
    scanf("%d", &n);
    int *a;
    a = (int *) malloc(n * sizeof(int));
    for (i = 0; i < n; i++) {
        scanf("%d", a + i);
        if (square(*(a + i)) == 1)
            cnt++;
    }
    printf("%d", cnt);
    free(a);

    return 0;
}
