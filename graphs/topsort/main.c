#include <stdio.h>

#include "funcs.h"
#include "structs.h"

//Modernized DFS process
int dfs(graph *g, list *stack, int *visited, int v) {
    visited[v - 1] = 1;
    list *tmp = g->first[v - 1];

    while (tmp) {
        if (visited[tmp->vert - 1] == 0)
            dfs(g, stack, visited, tmp->vert);
        if (visited[tmp->vert - 1] == 1)
            return 1;
        tmp = tmp->next;
    }

    free(tmp);

    visited[v - 1] = 2;
    add(stack, v);

    return 0;
}

//A Topological sorting function
void topsort(graph *g, int s) {
    list *stack = lcreate(0);
    int *visited = (int *) malloc(g->verts * sizeof(int));
    int stat;

    for (int i = 0; i < g->verts; i++)
        visited[i] = 0;

    stat = dfs(g, stack, visited, s);

    for (int v = 0; v < g->verts; v++)
        if (visited[v] == 0)
            stat = dfs(g, stack, visited, v + 1);

    if (stat)
        puts("impossible to sort");
    else
        print(stack->next);

    free(visited);
    free(stack);
}

int main () {
    FILE *in = fopen("in.txt", "r");
    int verts, edges;
    fscanf(in, "%d", &verts);

    if (fscanf(in, "%d", &edges) != 1) {
        puts("bad number of lines");
        fclose(in);
        return 0;
    }

    if (!initerr(verts, edges)) {
        fclose(in);
        return 0;
    }

    graph *g = gcreate(verts);
    int start, end, s = 0;
    int *visited = (int *) malloc(verts * sizeof(int));
    for (int i = 0; i < verts; i++)
        visited[i] = 0;

    for (int i = 0; i < edges; i++) {
        if (fscanf(in, "%d %d", &start, &end) != 2) {
            puts("bad number of lines");
            fclose(in);
            return 0;
        }

        if (!ederr(verts, start, end)) {
            fclose(in);
            return 0;
        }

        ladd(g, start - 1, end);
        visited[end - 1] = 1;
    }

    for (int i = 0; i < verts; i++)
        if (visited[i] == 0)
            s = i + 1;

    if (!s) {
        puts("impossible to sort");
        fclose(in);
        return 0;
    }

    free(visited);

    topsort(g, s);

    free(g);
    fclose(in);

    return 0;
}
