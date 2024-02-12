#include <stdio.h>

#include "tree.h"

int main() {
    FILE *in = fopen("in.txt", "r");

    int n;
    int tmp;
    fscanf(in, "%d", &n);

    avl *tree;

    for (int i = 0; i < n; i++) {
        fscanf(in, "%d", &tmp);
        tree = add(tree, tmp);
    }

    fclose(in);
    FILE *out = fopen("out.txt", "w");

    int h = height(tree);
    fprintf(out, "%d ", h);

    fclose(out);

    return 0;
}
