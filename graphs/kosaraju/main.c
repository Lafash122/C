#include <stdio.h>
#include <malloc.h>

#include "structs.h"

//The function of zeroing of the array
void nullarr(int *arr, int len) {
    for (int i = 0; i < len; i++)
        arr[i] = 0;
}

//The DFS function
void dfs(graph *g, int *visited, int v, list *stack) {
    visited[v] = 1;
    list *tmp = g->first[v];

    while (tmp) {
        if (!visited[tmp->dest])
            dfs(g, visited, tmp->dest, stack);
        tmp = tmp->next;
    }

    append(stack, v);

    free(tmp);
}

//The printing the DFS process
void dfsout(graph *g, int *visited, int v) {
    visited[v] = 1;
    printf("%d ", v);
    list *tmp = g->first[v];

    while (tmp) {
        if (!visited[tmp->dest])
            dfsout(g, visited, tmp->dest);
        tmp = tmp->next;
    }

    free(tmp);
}

void kosaraju (graph *g, graph *rev){
    int *visited = (int *) calloc(g->verts, sizeof(int));
    list *stack = lcreate(-1);
    int num = 0;

    for (int v = 0; v < g->verts; v++)
        if (!visited[v])
            dfs(g, visited, v, stack);

    nullarr(visited, g->verts);

    while (stack->next) {
        int v = pop(stack);
        if (!visited[v]) {
            printf("%d: ", ++num);
            dfsout(rev, visited, v);
            printf("\n");
        }
    }

    free(stack);
    free(visited);
}

int main() {
    int vertices, edges;
    scanf("%d", &vertices);
    scanf("%d", &edges);

    graph *g = gcreate(vertices);
    graph *rev = gcreate(vertices);
    int start, end;
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &start, &end);
        add(g, start, end);
        add(rev, end, start);
    }

    kosaraju(g, rev);

    free(g);
    free(rev);

    return 0;
}
