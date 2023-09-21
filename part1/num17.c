#include <stdio.h>

int main() {
    int a, b, c, d, e;
    scanf("%d %d", &a, &b);
    c = a % b;
    d = b % a;
    e = !(c && d);
    printf("%d", e);

    return 0;
}
