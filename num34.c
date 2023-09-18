#include <stdio.h>
#include <math.h>

int main() {
    float c = sqrt(49 + sqrt(50));
    int b = 48;
    while (b > 0) {
        c = sqrt(b + c);
        b--;
    }
    printf("%f", c);

    return 0;
}
