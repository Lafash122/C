#include <stdio.h>
#include <math.h>

int main() {
    float p0 = 1.29;
    float z = 1.25 * pow(10, -4);
    int h = 0;
    float p = p0 * pow(M_E, h * z * (-1));
    while (p >= 1) {
        h++;
        p = p0 * pow(M_E, h * z * (-1));
    }
    printf("%d", h);

    return 0;
}
