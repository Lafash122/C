#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

double func (double x) {
    return pow(M_E, x) * sin(x);
}

double integral (long long num) {
    double h = M_PI / num;
    double sum = 0, fin = 0, st;
    for (long long k = 0; k < num; k++) {
        st = fin;
        fin = func((k + 1) * h);
        sum = sum + ((st + fin) / 2);
    }
    return h * sum;
}

int main(int cnt, char **arr) {
    struct timespec start, end;

    long long num;
    num = atol(arr[1]);

    clock_gettime(CLOCK_MONOTONIC, &start);
    double result = integral(num);
    clock_gettime(CLOCK_MONOTONIC, &end);
    printf("The value of the integral: %f\n", result);
    printf("Programm working time: %f\n", end.tv_sec - start.tv_sec + 0.000000001 * (end.tv_nsec - start.tv_nsec));

    return 0;
}