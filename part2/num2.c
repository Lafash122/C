#include <stdio.h>
#include <malloc.h>

int gcd(int a, int b) {                         //The function that allow to search the greatest common division
    while (a != 0 && b != 0) {
        if (a > b)
            a = a % b;
        else
            b = b % a;
    }
    return a + b;
}

int main() {
    int n, i, num;
    int *x;
    scanf("%d", &n);
    x = (int *) malloc(n * sizeof(int));
    for (i = 0; i < n; i++)
        scanf("%d", x + i);

    num = gcd(*(x), *(x + 1));
    for (i = 2; i < n; i++)
        num = gcd(num, *(x + i));

    printf("%d", num);
    free(x);

    return 0;
}
