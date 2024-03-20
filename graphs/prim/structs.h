#ifndef PRIM_STRUCTS_H
#define PRIM_STRUCTS_H

#include <malloc.h>

#define graph struct graphs
#define list struct lists
#define edge struct edges

//The description the structure of adjacency list
list {
    int vert;
    int len;
    list *next;
};

graph {
    int verts;
    list **first;
};

//The description the structure of edge list
edge {
    int src;
    int dest;
    int len;
    edge *next;
};

//The function of creation a graph
graph *gcreate(int verts) {
    graph *inst = (graph *) malloc(sizeof(graph));
    inst->verts = verts;
    inst->first = (list **) malloc((verts + 1) * sizeof(list *));

    for (int i = 1; i <= verts; i++)
        inst->first[i] = NULL;

    return inst;
}

//The function of creation an adjacency list
list *lcreate(int vert, int len) {
    list *l = (list *) malloc(sizeof(list));
    l->vert = vert;
    l->len = len;
    l->next = NULL;

    return l;
}

//The function of creation an edge list
edge *ecreate(int s, int f, int l) {
    edge *ed = (edge *) malloc(sizeof(edge));
    ed->src = s;
    ed->dest = f;
    ed->len = l;
    ed->next = NULL;

    return ed;
}

//The function of addition a new edge to the adjacency list
void ladd(graph *g, int src, int dest, int len) {
    list *el = lcreate(dest, len);
    el->next = g->first[src];
    g->first[src] = el;
}

//The function that inserts edge in the list in increasing order
void insert(edge *q, edge *el) {
    if (q->next)
        if (el->len > q->next->len)
            insert(q->next, el);
        else {
            el->next = q->next;
            q->next = el;
        }
    else
        q->next = el;
}

//The function that gives the element and remove it from the list
edge *pop(edge *q) {
    if (q->next) {
        edge *tmp = q->next;
        q->next = tmp->next;
        tmp->next = NULL;

        return tmp;
    }
    return q;
}

//The function that prints the list
void print(edge *l) {
    while (l) {
        printf("%d %d\n", l->src, l->dest);
        l = l->next;
    }
}

#endif //PRIM_STRUCTS_H
