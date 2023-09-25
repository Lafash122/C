#include <stdio.h>
#include <math.h>

int primal(int num, int del) {                //The recursive function that allow to define prime numbers
    if (del >= (int)(sqrt(num) + 1))
        return 0;
    if (num % del == 0)
        return 1;
    else
        return primal(num, del + 1);
}

int main() {
    int n;
    scanf("%d", &n);
    if (primal(n, 2) == 1 || n == 1)
        printf("It is not a primal number");
    else
        printf("It is a primal number");

    return 0;
}
