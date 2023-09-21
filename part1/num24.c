#include <stdio.h>

int main() {
    float t;
    scanf("%f", &t);
    t = t - ((int) t / 5) * 5;
    if (t <= 3)
        printf("Green");
    else
        printf("Red");

    return 0;
}
