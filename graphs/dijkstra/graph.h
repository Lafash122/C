#ifndef GRAPHS_GRAPH_H
#define GRAPHS_GRAPH_H

#include <malloc.h>

#define list struct lists
#define gra struct graphs

//The description of adjacency list structure
list {
    int vert;
    long long int len;
    list *next;
};

gra {
    int verts;
    list **first;
};

//The function of creation of the graph
gra *gcreate(int verts) {
    gra *graph = (gra *) malloc(sizeof(gra));
    graph->verts = verts;
    graph->first = (list **) malloc((verts + 1) * sizeof(list *));
    for (int i = 1; i <= verts; i++)
        graph->first[i] = NULL;

    return graph;
}

//The function of creation of the adjacency list
list *lcreate(int vert, long long int len) {
    list *l = (list *) malloc(sizeof(list));
    l->vert = vert;
    l->len = len;
    l->next = NULL;

    return l;
}

//The function of addition a new edge
void add(gra *g, int start, int end, long long int len) {
    list *el = lcreate(end, len);
    el->next = g->first[start];
    g->first[start] = el;
}

//The function that inserts vertex in the stack in increasing order
void insert(list *pre, list *elem) {
    if (pre->next == NULL)
        pre->next = elem;
    else
        if (elem->len > pre->next->len)
            insert(pre->next, elem);
        else {
            elem->next = pre->next;
            pre->next = elem;
        }
}

#endif //GRAPHS_GRAPH_H
