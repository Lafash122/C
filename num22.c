#include <stdio.h>

int main() {
    int ax, ay, bx, by, cx, cy, dx, dy;
    int botx, boty, topx, topy;
    scanf("%d %d %d %d %d %d %d %d", &ax, &ay, &bx, &by, &cx, &cy, &dx, &dy);
    if (ax < cx)
        botx = ax;
    else
        botx = cx;
    
    if (ay < cy)
        boty = ay;
    else
        boty = cy;

    if (bx > dx)
        topx = bx;
    else
        topx = dx;

    if (by > dy)
        topy = by;
    else
        topy = dy;

    printf("(%d,%d) (%d,%d)", botx, boty, topx, topy);

    return 0;
}
