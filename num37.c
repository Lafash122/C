#include <stdio.h>
#include <math.h>

int main() {
    float a = 0;
    float b = 1;
    float x;
    while (b - a > 0.00001) {
        x = (b + a) / 2;
        if (((pow(a, 4) + 2 * pow(a, 3) - a - 1) < (pow(b, 4) + 2 * pow(b, 3) - b - 1)) &&
            (pow(x, 4) + 2 * pow(x, 3) - x - 1) >= 0)
            b = x;
        else
            a = x;
    }
    printf("%f", x);

    return 0;
}
