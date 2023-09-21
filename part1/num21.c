#include <stdio.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "Rus");
    int k;
    scanf("%d", &k);
    if (k % 10 == 1 && k % 100 != 11)
        printf("Мы нашли %d гриб", k);
    else if (k % 10 < 5 && k % 10 > 1 && k % 100 > 21 && k % 100 < 10)
        printf("Мы нашли %d гриба", k);
    else
        printf("Мы нашли %d грибов", k);

    return 0;
}
