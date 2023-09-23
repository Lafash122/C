#include <stdio.h>

//The recursive function that allow to search
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
