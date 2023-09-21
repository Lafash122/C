#include <stdio.h>

int main() {
    int c = 20 * 20 - 19 * 19;
    int b = 18;
    while (b > 0) {
        c = c - b * b;
        b--;
    }
    printf("%d", c);

    return 0;
}
