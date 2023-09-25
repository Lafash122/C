#include <stdio.h>

int droot(int num) {                        //The recursive function that allow to search the digital root
    if (num <= 9)
        return num;
    else
        return 1 + (droot(num - 1) % 9);
}

int main() {
    int n;
    scanf("%d", &n);
    printf("%d", droot(n));

    return 0;
}
