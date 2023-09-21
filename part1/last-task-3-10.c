#include <stdio.h>
#include <math.h>

int main() {
    int n, i, j, k;
    float sum = 0, multi, fact;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        multi = 1;
        for (j = i; j < 2 * n; j++) {
            fact = j - i + 1;
            k = j - i;
            while (k >= 1) {
                fact = fact * k;
                k--;
            }
            multi = multi * ((pow(-1, i) * (j + 1)) / (j - i + 1));
            printf("%f", multi);
            printf("\n\n");
        }
    sum = sum + multi;
    }
    printf("%f", sum);

    return 0;
}
