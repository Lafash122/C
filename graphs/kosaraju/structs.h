#ifndef KOSARAJU_STRUCTS_H
#define KOSARAJU_STRUCTS_H

#include <malloc.h>
#include <stdio.h>

#define graph struct graphs
#define list struct lists

//The description of structure of adjacency list
graph {
    int verts;
    list **first;
};

list {
    int dest;
    list *next;
};

//The function of creation of graph
graph *gcreate(int verts) {
    graph *g = (graph *) malloc(sizeof(graph));
    g->verts = verts;
    g->first = (list **) malloc(verts * sizeof(list *));

    for (int i = 0; i < verts; i++)
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
}

//The function of addition a new element to the list
void append(list *l, int val) {
    list *el = lcreate(val);
    el->next = l->next;
    l->next = el;
}

//The function that value of the element and remove it from the list
int pop(list *l) {
    if (l->next) {
        list *tmp = l->next;
        l->next = tmp->next;
        tmp->next = NULL;

        return tmp->dest;
    }

    return l->dest;
}

#endif //KOSARAJU_STRUCTS_H
