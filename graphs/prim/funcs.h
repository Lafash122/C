#ifndef PRIM_FUNCS_H
#define PRIM_FUNCS_H

#include <stdio.h>
#include <limits.h>

#define VERT_MAX 5000
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
int ederr(int v, int s, int f, long long l) {
    if (s < N_MIN || s > v || f < N_MIN || f > v) {
        puts("bad vertex");
        return 0;
    }

    if (l < MIN || l > INT_MAX) {
        puts("bad length");
        return 0;
    }

    return 1;
}

//The function that checks a spanning tree without algorithms
int span(int v, int e) {
    if (v == 0 || (v - e) > 1) {
        puts("no spanning tree");
        return 0;
    }

    if (v == 1) {
        puts("");
        return 0;
    }

    return 1;
}

#endif //PRIM_FUNCS_H
