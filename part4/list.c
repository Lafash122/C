#include <stdio.h>
#include <malloc.h>

#define LIST struct list

//The description of the attributes of the list
LIST {
    int key;
    float value;
    struct list *next;
};

//The function that creates list
LIST *create(int key, float value) {
    LIST *el = (LIST *) malloc(sizeof(LIST));
    el->key = key;
    el->value = value;
    el->next = NULL;
    return el;
}

//The function that adds the element in the list
void push(LIST *L, LIST *el) {
    LIST *first = L->next;
    el->next = first;
    L->next = el;
}

//The function that allow to print the list
void print(LIST *L) {
    LIST *ptr = L->next;
    while (ptr) {
        printf("%d: %f\n", ptr->key, ptr->value);
        ptr = ptr->next;
    }
}

//The function that allow to check if the list is empty
int empty(LIST *L) {
    if (L->next)
        return 0;
    return 1;
}

//The function that searches for a value by key
float search(LIST *L, int key) {
    if (!empty(L)) {
        LIST *ptr = L->next;
        while (ptr) {
            if (key == ptr->key)
                return ptr->value;
            ptr = ptr->next;
        }
        return 0;
    }
    return 0;
}

//The function that allow to get the length of the list
int listlen(LIST *L) {
    int len = 0;
    LIST *p = L->next;

    while (p) {
        len++;
        p = p->next;
    }
    return len;
}

//The function that allow to delete even keys
void deleven(LIST *L) {
    if (!empty(L)) {
        LIST *before = L;
        LIST *el = before->next;

        while (el)
            if ((el->key) % 2 == 0) {
                before->next = el->next;
                free(el);
                el = before->next;
            }
            else {
                before = el;
                el = el->next;
            }
    }
}

//The function that allow to delete odd keys
void delodd(LIST *L) {
    if (!empty(L)) {
        LIST *before = L;
        LIST *el = before->next;

        while (el)
            if ((el->key) % 2 == 1) {
                before->next = el->next;
                free(el);
                el = before->next;
            }
            else {
                before = el;
                el = el->next;
            }
    }
}

//The function that allow to unite two lists
void unite(LIST *L, LIST *K) {
    while (L->next) {
        L = L->next;
    }
    L->next=K->next;
}

int main() {
    LIST *L;
    L = create(0, 0);
    int ln, lkey;
    scanf("%d", &ln);
    float lvalue;

    for (int i = 0; i < ln; i++) {
        scanf("%d %f", &lkey, &lvalue);
        LIST *p = create(lkey, lvalue);
        push(L, p);
    }

    int k;
    printf("Which key value do you want to know:");
    scanf("%d", &k);
    printf("The key value is %f\n", search(L, k));

    printf("\nThe length of the list is %d\n", listlen(L));
    printf("\n");

    deleven(L);
    print(L);
    printf("\n");

    LIST *K;
    K = create(0, 0);
    int kn, kkey;
    scanf("%d", &kn);
    float kvalue;

    for (int i = 0; i < kn; i++) {
        scanf("%d %f", &kkey, &kvalue);
        LIST *p = create(kkey, kvalue);
        push(K, p);
    }

    printf("\n");
    delodd(K);
    print(K);
    printf("\n");

    unite(L, K);
    printf("\n");
    print(L);

    return 0;
}
