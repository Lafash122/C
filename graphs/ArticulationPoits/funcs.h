#ifndef ARTICULATIONPOINTS_FUNCS_H
#define ARTICULATIONPOINTS_FUNCS_H

#include <malloc.h>

//The function of the zeroing of array
void null(int *arr, int len) {
    for (int i = 1; i <= len; i++)
        arr[i] = 0;
}

//The function of searching the minimum element
int min(int x, int y) {
    if (x < y)
        return x;
    return y;
}

#endif //ARTICULATIONPOINTS_FUNCS_H
