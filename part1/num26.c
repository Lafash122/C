#include <stdio.h>
#include <math.h>

int main() {
    int a, b, c, d, e, f;
    scanf("%d %d %d %d %d %d", &a, &b, &c, &d, &e, &f);
    if (e == c && f == d)
        printf("It's not a move.\n");
    else if ((abs(e - a) == 2 && abs(f - b) == 1) || (abs(e - a) == 1 && abs(f - b) == 2)) {
        if (e == c || f == d || (abs(e - c) / abs(f - d) == 1))
            printf("The queen captures the knight.\n");
        else
            printf("Valid move.\n");
    }
    else
        printf("Invalid move.\n");

    return 0;
}
