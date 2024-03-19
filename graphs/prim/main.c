#include <stdio.h>
#include <malloc.h>

#include "funcs.h"
#include "structs.h"

void prim(graph *g, int s, int edges) {
    int verts = g->verts;
    int *visited = (int *) malloc((verts + 1) * sizeof(int));
    for (int i = 1; i <= verts; i++) {
        visited[i] = 0;
    }
    visited[s] = 1;

    edge *queue = ecreate(s, s, 0);
    list *near = g->first[s];
    while(near) {
        insert(queue, ecreate(s, near->vert, near->len));
        near = near->next;
    }

    edge *spantree = ecreate(s, s, 0);
    while (queue->next) {
        edge *tmp = pop(queue);
        int vert = tmp->dest;

        if (!visited[vert]) {
            near = g->first[vert];
            while (near) {
                if (!visited[near->vert])
                    insert(queue, ecreate(vert, near->vert, near->len));
                near = near->next;
            }

            insert(spantree, tmp);
            visited[tmp->dest] = 1;
        }
    }

    for (int i = 1; i <= verts; i++)
        if (!visited[i]) {
            puts("no spanning tree");
            return;
        }

    print(spantree->next);

    free(near);
    free(queue);
    free(spantree);
}

int main() {
    int vert, ed;
    scanf("%d", &vert);
    scanf("%d", &ed);

    if (!initerr(vert, ed)) {
        return 0;
    }

    graph *g = gcreate(vert);
    int start, end, s;
    long long len;
    for (int i = 0; i < ed; i++) {
        if (scanf("%d %d %lld", &start, &end, &len) != 3) {
            puts("bad number of lines");
            return 0;
        }

        if (!ederr(vert, start, end, len))
            return 0;

        if (start != end) {
            ladd(g, start, end, len);
            ladd(g, end, start, len);
        }
        else
            ladd(g, start, end, len);
        s = start;
    }

    if (!span(vert, ed))
        return 0;

    prim(g, s, ed);

    free(g);

    return 0;
}