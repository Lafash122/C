#include <stdio.h>

int main() {
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    if ((c > a) || ((d > b) && (c == a)) || ((d > b) && (d > a)))
        printf("0");
    else if (a / c > b / d)
        printf("%d", (a / c) * (b / d));
    else
        printf("%d", (a / d) * (b / c));

    return 0;
}
