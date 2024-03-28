#include <stdio.h>

#include "funcs.h"
#include "structs.h"

int getnum(int *p, int n, int s, int d) {
    if ((p[s] + p[d]) == 0)
        return ++n;
    else if((p[s] * p[d]) == 0)
        return max(p[s], p[d]);
    return min(p[s], p[d]);
}

void kruskal(edge *stack, int verts) {
    int *visited = (int *) malloc((verts + 1) * sizeof(int));
    int *parts = (int *) malloc((verts + 1) * sizeof(int));
    for (int i = 1; i <= verts; i++) {
        visited[i] = 0;
        parts[i] = 0;
    }

    edge *spantree = create(0, 0, 0);
    edge *tmp = pop(stack);
    int src = tmp->src, dest = tmp->dest;
    int num = 1, size = verts - 2;

    insert(spantree, tmp);
    visited[src] = 1, visited[dest] = 1;
    parts[src] = num, parts[dest] = num;

    while (size && stack->next) {
        tmp = pop(stack);
        src = tmp->src, dest = tmp->dest;
        num = getnum(parts, num, src, dest);

        if (!(visited[src] && visited[dest])) {
            insert(spantree, tmp);
            visited[src] = 1 ,visited[dest] = 1;
            parts[src] = num, parts[dest] = num;
            size--;
        }

        else
            if (parts[src] != parts[dest]) {
                insert(spantree, tmp);
                visited[src] = 1 ,visited[dest] = 1;
                parts[src] = num, parts[dest] = num;
                size--;
            }
    }

    for (int i = 1; i <= verts; i++)
        if (!visited[i]) {
            puts("no spanning tree");
            return;
        }

    print(spantree->next);
    free(spantree);
    free(tmp);
}

int main() {
    int vert, edges;
    scanf("%d", &vert);
    scanf("%d", &edges);

    if (!initerr(vert, edges))
        return 0;

    edge *stack = create(0, 0, 0);
    int start, end;
    long long len;
    for (int i = 0; i < edges; i++) {
        if (scanf("%d %d %lld", &start, &end, &len) != 3) {
            puts("bad number of lines");
            return 0;
        }

        if (!ederr(vert, start, end, len))
            return 0;

        edge *e = create(start, end, len);
        insert(stack, e);
    }

    if (!span(vert, edges))
        return 0;

    kruskal(stack, vert);

    free(stack);

    return 0;
}
