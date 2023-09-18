#include <stdio.h>

int main() {
    int a1, a2, a3, b1, b2, c1, c2, c3, d2, d3;
    scanf("%d %d %d", &a3, &a2, &a1);
    scanf("%d %d", &b2, &b1);
    c1 = (a1 + b1) % 10;
    d2 = (a1 + b2) / 10;
    c2 = (a2 + b2 + d2) % 10;
    d3 = (a2 + b2 + d2) / 10;
    c3 = a3 + d3;
    printf("%d %d %d", c3, c2, c1);

    return 0;
}
