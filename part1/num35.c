#include <stdio.h>
#include <math.h>

int main() {
    float a = M_PI / 10;
    float s = 0;
    int i = 0;
    while (i < 5) {
        s = s + sin((i * 2 + 1) * M_PI / 20);
        i++;
    }
    printf("%f", s * 2 * a);

    return 0;
}
