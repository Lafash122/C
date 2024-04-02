#ifndef TOPSORT_FUNCS_H
#define TOPSORT_FUNCS_H

#include <stdio.h>

#define VERT_MAX 2000
#define MIN 0
#define N_MIN 1

//The function that checks initial input errors
int initerr(int v, int e) {
    if (v < MIN || v > VERT_MAX) {
        puts("bad number of vertices");
        return 0;
    }

    if (e < MIN || e > (v * (v + 1) / 2)) {
        puts("bad number of edges");
        return 0;
    }

    return 1;
}

//The function that checks edges errors
int ederr(int v, int s, int f) {
    if (s < N_MIN || s > v || f < N_MIN || f > v) {
        puts("bad vertex");
        return 0;
    }

    if (s == f) {
        puts("bad number of edge");
        return 0;
    }

    return 1;
}

#endif //TOPSORT_FUNCS_H
