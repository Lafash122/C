#include <stdio.h>

int main() {
    float a = 199 + 1 / 201;
    int b = 197;
    while (b > 0) {
        a = b + 1 / a;
        b -= 2;
    }
    printf("%f", a);
    
    return 0;
}
