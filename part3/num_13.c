#include <stdio.h>
#include <string.h>

int main() {
    char num[80] = "";
    int i, cnt = 0, len, luck = 0, fhalf, shalf;
    while (luck != 1) {
        fgets(num, 80, stdin);
        cnt++;
        len = strlen(num);
        fhalf = 0, shalf = 0;
        if ((len - 1) % 2 == 0) {
            for (i = 0; i <= (len - 2) / 2; i++) {
                fhalf = fhalf + ((int) num[i] - 48);
                shalf = shalf + ((int) num[len - 2 - i] - 48);
            }
            if (shalf == fhalf) {
                printf("%d", cnt);
                luck++;
                return 0;
            }
        }
    }
}
