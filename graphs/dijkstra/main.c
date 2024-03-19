#include <stdio.h>
#include <malloc.h>
#include <limits.h>

#include "graph.h"
#include "funcs.h"

//The function that counts path with Dijkstra's algorithm
void dijkstra(gra *graph, int start, int finish) {
    int verts = graph->verts;
    int overcnt= 0;
    long long *lens = (long long *) malloc((verts + 1) * sizeof(long long));
    int *path = (int *) malloc((verts + 1) * sizeof(int));
    for (int i = 1; i <= verts; i++) {
        lens[i] = LLONG_MAX;
        path[i] = 0;
    }

    lens[start] = 0;
    path[start] = start;

    list *stack = lcreate(0, 0);
    insert(stack, lcreate(start, 0));
    while (stack->next) {
        list *v = stack->next;
        int vert = v->vert;
        stack->next = v->next;
        free(v);

        long long len = lens[vert];
        list *nearv = graph->first[vert];
        while(nearv) {
            long long newlen = nearv->len + len;
            if (newlen <= lens[nearv->vert]) {
                lens[nearv->vert] = newlen;
                path[nearv->vert] = vert;
                insert(stack, lcreate(nearv->vert, newlen));
            }
            nearv = nearv->next;
        }
    }

    for (int i = 1; i <= verts; i++) {
        long long len = lens[i];
        if (len == LLONG_MAX)
            printf("oo ");
        else if (len > INT_MAX)
            printf("INT_MAX+ ");
        else
            printf("%lld ", len);
    }
    printf("\n");

    for (int i = 1; i <= verts; i++) {
        if ((lens[i] >= INT_MAX) && (lens[i] != LLONG_MAX))
            overcnt++;
    }

    if (lens[finish] == LLONG_MAX) {
        puts("no path");
        return;
    }

    else if ((lens[finish] > INT_MAX) && (overcnt > 2)) {
        puts("overflow");
        return;
    }

    while (path[finish] != finish) {
        printf("%d ", finish);
        finish = path[finish];
    }
    printf("%d", finish);

    free(lens);
    free(path);
}

int main() {
    FILE *in = fopen("in.txt", "r");
    int vert, s, f, ed;
    scanf("%d", &vert);
    scanf("%d %d", &s, &f);
    scanf("%d", &ed);
    if (!errors(vert, s, f, ed)) {
        fclose(in);
        return 0;
    }

    gra *graph = gcreate(vert);
    int start, end;
    long long len;
    for (int i = 0; i < ed; i++) {
        scanf("%d %d %lld", &start, &end, &len);
        if (!lenerr(len)) {
            fclose(in);
            return 0;
        }

        add(graph, start, end, len);
        add(graph, end, start, len);
    }

    dijkstra(graph, s, f);
    free(graph);

    fclose(in);
    return 0;
}
