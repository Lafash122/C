#ifndef GRAPHS_FUNCS_H
#define GRAPHS_FUNCS_H

#include <stdio.h>

#define VERT_MAX 5000
#define MIN 0
#define N_MIN 1

//The function that checks input errors
int errors(int v, int s, int f, int e) {
    if (v < MIN || v > VERT_MAX) {
        puts("bad number of vertices");
        return 0;
    }

    if (e < MIN || e > (v * (v + 1) / 2)) {
        puts("bad number of edges");
        return 0;
    }

    if ((s < N_MIN || s > v) || (f < N_MIN || f > v)) {
        puts("bad vertex");
        return 0;
    }

    return 1;
}

//The function that checks length correctness
int lenerr(long long int len) {
    if (len < 0 || len > INT_MAX) {
        puts("bad length");
        return 0;
    }
    return 1;
}

#endif //GRAPHS_FUNCS_H
