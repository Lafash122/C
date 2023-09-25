#include <stdio.h>

int sumel(int num) {                            //The recursive function that allow to search the sum of the digits of the number
    if (num <= 9)
        return num;
    else
        return sumel(num / 10) + (num % 10);
}

int main() {
    int n;
    scanf("%d", &n);
    printf("%d", sumel(n));

    return 0;
}
