#include <stdio.h>
#include <math.h>

int main() {
    int a, b;
    b = 0;
    scanf("%d", &a);
    for (int i = 4; i > -1; i--) {
        b = b + (a % 10) * pow(10, i);
        a = a / 10;
    }
    printf("%d", b);

    return 0;
}
