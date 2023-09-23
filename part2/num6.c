#include <stdio.h>

//The recursion function that allow to search the sum of the digits of the number
int sumel(int num) {
    if (num == 0) return 0;
    else return sumel(num / 10) + (num % 10);
}

int main() {
    int n;
    scanf("%d", &n);
    printf("%d", sumel(n));

    return 0;
}
