#include <stdio.h>

int main() {
    int h, m, cw, ccw, min;
    scanf("%d %d", &h, &m);
    cw = h * 5 + 15 + (h * 5 + 15) / 60 * 5;
    ccw = h * 5 - 15 + (60 * ((h * 5 - 15) <= 0));
    min = ((((ccw - m) < (cw - m)) && ((ccw - m) >= 0)) * (ccw - m))
          + ((cw - m) * (!(((ccw - m) < (cw - m)) && ((ccw - m) >= 0)) && (cw - m >= 0)))
          + ((ccw - m) * (cw - m < 0)) + ((((h + 1) * 5 + 15) + (60 - ccw)) * ((ccw - m) < 0));
    printf("%d", min);

    return 0;
}
