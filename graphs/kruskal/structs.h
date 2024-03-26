#ifndef KRUSKAL_STRUCTS_H
#define KRUSKAL_STRUCTS_H

#include <malloc.h>
#include <stdio.h>

#define edge struct edges

//The description the structure of edge list
edge {
    int src;
    int dest;
    int len;
    edge *next;
};

//The function of creation an edge list
edge *create(int s, int f, int l) {
    edge *ed = (edge *) malloc(sizeof(edge));
    ed->src = s;
    ed->dest = f;
    ed->len = l;
    ed->next = NULL;

    return ed;
}

//The function that inserts edges in the list in increasing order
void insert(edge *list, edge *ed) {
    if (list->next)
        if (ed->len > list->next->len)
            insert(list->next, ed);
        else {
            ed->next = list->next;
            list->next = ed;
        }
    else
        list->next = ed;
}

//The function that prints the list
void print(edge *list) {
    while(list) {
        printf("%d %d\n", list->src, list->dest);
        list = list->next;
    }
}

//The function that gives the element and remove it rom the list
edge *pop(edge *list) {
    if (list->next) {
        edge *tmp = list->next;
        list->next = tmp->next;
        tmp->next = NULL;

        return tmp;
    }
    return list;
}

#endif //KRUSKAL_STRUCTS_H
