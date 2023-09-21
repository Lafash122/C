#include <stdio.h>

int main() {
    int a;
    scanf("%d", &a);
    int b = a * a;
    int c = b * b;
    int d = c * c;
    int e = d * d;
    int f = e * d * c;
    printf("%d", f);

    return 0;
}
