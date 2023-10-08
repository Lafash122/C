#include <stdio.h>
#include <string.h>

int main() {
    char sent[80] = "";
    fgets(sent, 80, stdin);
    char seps[] = " ,:!()?.;'-";
    int i, j, end;
    end = strlen(sent) - 1;
    for (i = end; i >= 0; i--) {
        if (strchr(seps, sent[i]) != NULL) {
            for (j = i + 1; j < end; j++)
                printf("%c", sent[j]);
            end = i;
            printf(" ");
        }
        else if (i == 0)
            for (j = i; j < end; j++)
                printf("%c", sent[j]);

    }

    return 0;
}