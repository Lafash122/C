#include <stdio.h>

int main() {
    int k, m, n;
    scanf("%d %d %d", &n, &k, &m);
    if (m - k - 1 < n - m + k - 1)
        printf("%d", m - k - 1);
    else
        printf("%d", n - m + k - 1);

    return 0;
}
