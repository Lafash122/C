#include <stdio.h>

int main() {
    char num[6] = "";
    char answer[6] = "";
    fgets(num, 6, stdin);
    int i, j, k;
    for (i = 0; i < 25; i++)
        puts("");

    for (i = 0; i < 10; i++) {
        int bulls = 0, cows = 0;
        fgets(answer, 6, stdin);
        for (j = 0; j < 4; j++) {
            if (answer[j] == num[j])
                bulls++;
            else
                for (k = 0; k < 4; k++)
                    if (answer[k] == num[j] && k != j)
                        cows++;
        }
        printf("Bulls: %d, Cows: %d.\n", bulls, cows);
        if (bulls == 4) {
            puts("\nYou win!");
            return 0;
        }
    }
    puts("\nYou lose");
    printf("The correct number is ");
    puts(num);
    return 0;
}
