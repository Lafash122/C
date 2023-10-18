#include <stdio.h>
#include <string.h>
#include <math.h>

//The function that allow to check bases
int isbase(int base1, int base2) {
    if (2 <= base1 && base1 <= 16 && 2 <= base2 & base2 <= 16)
        return 1;
    return 0;
}

//The function that allow to check base of number
int isnbase(char *num, int base) {
    for (int i = 0; i < strlen(num) - 1; i++) {
        if ('0' <= num[i] && num[i] <= '9' && (num[i] - 48) < base)
            continue;
        else if ('a' <= num[i] && num[i] <= 'f' && (num[i] - 87) < base)
            continue;
        else if ('A' <= num[i] && num[i] <= 'F' && (num[i] - 55) < base)
            continue;
        else if (num[i] == '.')
            continue;
        else
            return 0;
    }
    return 1;
}

//The function that allow to define number of occurrence some char in a string
int cntr(char *str, char chr) {
    int cnt = 0;
    for (int i = 0; i < strlen(str); i++)
        if (str[i] == chr)
            cnt++;
    return cnt;
}

//The function that allow to convert char to dec number
//The max base for conversion is hex
int hchrtodgt(char el) {
    if ('0' <= el && el <= '9')
        return (int) (el - 48);
    else if ('a' <= el && el <= 'f')
        return (int) (el - 87);
    else
        return (int) (el - 55);
}

//The function that allow to convert string format to dec
double todec(char *str, int base) {
    char point = '.';
    int len, dot, i;
    double sum = 0;
    len = strlen(str) - 2;

    if (strchr(str, point) != NULL) {
        dot = (int) (strchr(str, point) - str);

        for (i = dot; i > 0; i--)
            sum += hchrtodgt(str[i - 1]) * pow(base, (dot - i));

        for (i = dot; i < len; i++)
            sum += (hchrtodgt(str[i + 1]) / pow(base, (i - dot + 1)));
    }
    else
        for (i = len; i >= 0; i--)
            sum += hchrtodgt(str[i]) * pow(base, (len - i));
    return sum;
}

int main() {
    int b1, b2, len, d, i = 0, intfx;
    long long int intx;
    scanf("%d %d\n", &b1, &b2);
    char x[80] = "";
    fgets(x, 80, stdin);
    double dec, fx;

    if (!isbase(b1, b2) || !isnbase(x, b1) || cntr(x, '.') > 1) {
        puts("bad input");
        return 0;
    }

    dec = todec(x, b1);
    intx = (long long int) dec;
    fx = dec - intx;
    char num[80];

    if (intx == 0)
        printf("0");

    while (intx > 0) {
        d = intx % b2;
        if (0 <= d && d <= 9)
            d = (char) (d + 48);
        else
            d = (char) (d + 87);
        num[i] = d;
        intx = intx / b2;
        i++;
    }
    len = strlen(num) - 1;

    for (i = len; i >= 0; i--)
        printf("%c", num[i]);

    if (fx != 0) {
        printf(".");
        for (i = 0; i < 12; i++) {
            intfx = fx * b2;
            fx = fx * b2 - intfx;
            if (0 <= intfx && intfx <= 9)
                printf("%d", intfx);
            else
                printf("%c", intfx + 87);
        }
    }
    return 0;
}
