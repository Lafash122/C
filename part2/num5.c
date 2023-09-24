#include <stdio.h>
#include <malloc.h>
#include <math.h>

float len(float x1, float x2, float y1, float y2) {        //The function that allow to search a length between two points
    return sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
}

float area(float a, float b, float c) {                    //The function that allow to search an area of triangle by three sides
    float p = (a + b + c) / 2;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}

int main() {
    int n, i;
    float sum = 0, aside, bside, cside, trarea;
    scanf("%d", &n);
    float *x, *y;
    x = (float *) malloc(n * sizeof(float));
    y = (float *) malloc(n * sizeof(float));
    for (i = 0; i < n; i++)
        scanf("%f %f", x + i, y + i);

    for (i = 0; i < n - 2; i++) {
        aside = len(x[0], x[i + 1], y[0], y[i + 1]);
        bside = len(x[i + 1], x[i + 2], y[i + 1], y[i + 2]);
        cside = len(x[i + 2], x[0], y[i + 2], y[0]);
        trarea = area(aside, bside, cside);
        sum = sum + trarea;
    }
    printf("%f", sum);
    free(x);
    free(y);

    return 0;
}
