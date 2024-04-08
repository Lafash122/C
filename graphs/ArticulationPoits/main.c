#include <stdio.h>
#include <malloc.h>

#include "structs.h"
#include "funcs.h"

//The function that gets current color of the vertex
int getcol(int *colors, int src, int dest, int color) {
    if (colors[src] == 0)
        return ++color;
    else if ((colors[src] > 0) && (colors[dest] == 0))
        return colors[src];
    return min(colors[src], colors[dest]);
}

//The modernized DFS function
void dfs(graph *g, int *visited, int *colors, int v, int color) {
    visited[v] = 1;
    list *tmp = g->first[v];

    while (tmp) {
        if (!visited[tmp->dest]) {
            color = getcol(colors, v, tmp->dest, color);
            colors[tmp->dest] = color;
            dfs(g, visited, colors, tmp->dest, color);
        }
        tmp = tmp->next;
    }
    free(tmp);
}

//Checks that colors are different
//The color of the current vertex is not taken into account
int colchek(int *cols, int len) {
    for (int i = 1; i <= len; i++)
        if (cols[i] > 1)
            return 1;
    return 0;
}

int main() {
    int vertices, edges;
    scanf("%d", &vertices);
    scanf("%d", &edges);

    //Some undirected graph initialization
    graph *g = gcreate(vertices);
    int start, end;
    int *visited = (int *) calloc(vertices + 1, sizeof(int));
    int *colors = (int *) calloc(vertices + 1, sizeof(int));
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &start, &end);
        add(g, start, end);
        add(g, end, start);
    }

    //Initial color always equals zero
    int color = 0;
    for (int v = 1; v <= vertices; v++) {
        dfs(g, visited, colors, v, color);
        if (colchek(colors, vertices))
            printf("%d - is articulation point\n", v);
        else
            printf("%d - is not articulation point\n", v);
        //Zeroing list of the color and the visit status of the vertex
        null(visited, vertices);
        null(colors, vertices);
        //Zeroing the initial color
        color = 0;
    }

    free(visited);
    free(colors);
    free(g);

    return 0;
}