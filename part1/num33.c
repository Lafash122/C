#include <stdio.h>
#include <math.h>

int main() {
    int x, n;
    int i = 1;
    float a = 1;
    float b = 1;
    scanf("%d %d", &x, &n);
    while (i <= n) {
        b = b * i;
        a = a + (float) (pow(-1, i) * (pow(x, i) / b));
        i++;
    }
    printf("%f", a);

    return 0;
}
