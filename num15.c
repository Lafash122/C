#include <stdio.h>
#include <math.h>

int main() {
    float y, angle, hours, minutes;
    scanf("%f", &y);
    hours = (2 * M_PI - y) / M_PI * 6;
    minutes = (2 * M_PI - y) / M_PI * 360;
    angle = (float) ((int) minutes % 60) / 60 * 2 * M_PI;
    printf("Hours: %d; Minutes: %d; Angle: %f", (int) hours, (int) minutes % 60, angle);

    return 0;
}
