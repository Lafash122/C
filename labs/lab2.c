#include <stdio.h>
#include <string.h>

#define SIZE 80

//The function that allow to search strings with repeat's letters
int uniq(char *str, int len) {
    for (int i = 0; i < len; i++)
        for (int j = i + 1; j < len; j++)
            if (str[i] == str[j])
                return 0;
    return 1;
}

//The function that allow to define if string have only digits
int dgt(char *str, int len) {
    for (int i = 0; i < len; i++)
        if (str[i] > '9' || str[i] < '0')
            return 0;
    return 1;
}

//The function that allow to define decrease sequence
int isdecr(char *str, int len) {
    for (int i = 1; i < len; i++)
        if (str[i - 1] <= str[i])
            return 0;
    return 1;
}

//This function allow to search the id of the minimum element in the string
//This element bigger than the given one
int minstr(char *str, char simb) {
    int len = strlen(str);
    for (int i = 0; i < len; i++)
        if (str[i] > simb)
            return i;
    return 0;
}

int main() {
    char p[SIZE] = "";
    char end[SIZE] = "";
    fgets(p, SIZE, stdin);
    int n, len, i, j, k;
    scanf("\n%d", &n);
    len = strlen(p) - 1;

    if (!uniq(p, len) || !dgt(p, len)) {
        printf("bad input");
        return 0;
    }

    for (k = 0; k < n; k++) {
        if (isdecr(p, len))
            return 0;

        i = len - 1;
        j = 0;
        while (p[i + 1] < p[i]) {
            end[j] = p[i];
            j++;
            i--;
        }

        char bad = p[i];
        p[i] = p[len - minstr(end, bad) - 1];
        end[minstr(end, bad)] = bad;

        for (j = i + 1; j < len; j++)
            p[j] = end[j - i - 1];

        printf("%s", p);
    }

    return 0;
}
