#ifndef ARTICULATIONPOINTS_STRUCTS_H
#define ARTICULATIONPOINTS_STRUCTS_H

#include <stdio.h>
#include <malloc.h>

#define graph struct graphs
#define list struct lists

//The description of structure of adjacency list
graph {
    int vertices;           //The number of vertices
    int *size;              //The numbers of neighbors of the vertex
    list **first;           //The link to the adjacency list
};

list {
    int dest;               //The adjacency vertex
    list *next;             //The link to the next element
};

//The function of creation of graph
graph *gcreate(int verts) {
    graph *g = (graph *) malloc(sizeof(graph));
    g->vertices = verts;
    g->first = (list **) malloc((verts + 1) * sizeof(list *));

    int *sizes = (int *) calloc(verts + 1, sizeof(int));
    g->size = sizes;

    for (int i = 1; i <= verts; i++)
        g->first[i] = NULL;

    return g;
}

//The function of creation of adjacency list
list *lcreate(int vert) {
    list *l = (list *) malloc(sizeof(list));
    l->dest = vert;
    l->next = NULL;

    return l;
}

//The function of addition a new vertex to adjacency list
void add(graph *g, int src, int dest) {
    list *el = lcreate(dest);
    el->next = g->first[src];
    g->first[src] = el;
    g->size[src]++;
}


#endif //ARTICULATIONPOINTS_STRUCTS_H
