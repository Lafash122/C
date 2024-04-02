#ifndef TOPSORT_STRUCTS_H
#define TOPSORT_STRUCTS_H

#include <stdio.h>
#include <malloc.h>

#define graph struct graphs
#define list struct lists

//The description of structure of the adjacency list
list {
    int vert;
    list *next;
};

graph {
    int verts;
    list **first;
};

//The function of creation a graph
graph *gcreate(int verts) {
    graph *g = (graph *) malloc(sizeof(graph));
    g->verts = verts;
    g->first = (list **) malloc(verts * sizeof(list *));

    for (int i = 0; i < verts; i++)
        g->first[i] = NULL;

    return g;
}

//The function of creation a list
list *lcreate(int vert) {
    list *l = (list *) malloc(sizeof(list));
    l->vert = vert;
    l->next = NULL;

    return l;
}

//The function of addition a new vertex to adjacency list
void ladd(graph *g, int src, int dest) {
    list *el = lcreate(dest);
    el->next = g->first[src];
    g->first[src] = el;
}

//The function of addition a new element to some stack
void add(list *stack, int value) {
    list *el = lcreate(value);
    el->next = stack->next;
    stack->next = el;
}

//The function of printing a stack
void print(list *stack) {
    while (stack) {
        printf("%d ", stack->vert);
        stack = stack->next;
    }
}

#endif //TOPSORT_STRUCTS_H
