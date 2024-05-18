#ifndef HUFFMAN_STRUCTS_H
#define HUFFMAN_STRUCTS_H

#include <stdio.h>
#include <malloc.h>

#define tree struct TREE
#define list struct LIST
#define bins struct BINSEQUENSE
#define bits struct BITSTREAM

tree {
    char sym;
    int freq;
    tree *right;
    tree *left;
};

list {
    tree *data;
    list *next;
};

bins {
    char sym;
    unsigned int code;
    short size;
};

bits {
    FILE *dest;
    char buff;
    short size;
};

//Creation a tree
tree *tcreate(char sym) {
    tree *leaf = (tree *) malloc(sizeof(tree));

    leaf->sym = sym;
    leaf->freq = 1;
    leaf->left = NULL;
    leaf->right = NULL;

    return leaf;
}

//Merging two trees
tree *merge(tree *left, tree *right) {
    tree *root = (tree *) malloc(sizeof(tree));

    root->sym = 0;
    root->freq = left->freq + right->freq;
    root->left = left;
    root->right = right;

    return root;
}

//Print the tree
void inorder(tree *t) {
    if (t->left)
        inorder(t->left);
//    printf("%c ", t->sym);
    printf("%c %d ", t->sym, t->freq);
    if (t->right)
        inorder(t->right);
}



//Creation a list
list *lcreate(tree *node) {
    list *head = (list *) malloc(sizeof(list));

    head->data = node;
    head->next = NULL;

    return head;
}

//Insertion an element in non-decreasing order at the list
void insert(list *init, list *el) {
    if (init->next != NULL)
        if (el->data->freq > init->next->data->freq)
            insert(init->next, el);
        else {
            el->next = init->next;
            init->next = el;
        }
    else
        init->next = el;
}

//Taking the tree from the list
tree *pop(list *l) {
    if (l->next != NULL) {
        list *tmp = l->next;
        l->next = tmp->next;
        tmp->next = NULL;

        return tmp->data;
    }
    return l->data;
}

//Print the list
void print(list *l) {
    while (l) {
        inorder(l->data);
        printf("\t");
        l = l->next;
    }
    puts("");
}



//Creation a binary sequence of the symbol
bins *bcreate(char sym, unsigned int code, short size) {
    bins *seq = (bins *) malloc(sizeof(bins));

    seq->sym = sym;
    seq->code = code;
    seq->size = size;

    return seq;
}



//Creation a bitstream
bits *screate(FILE *dest) {
    bits *file = (bits *) malloc(sizeof(bits));

    file->dest = dest;
    file->buff = 0;
    file->size = 0;

    return file;
}

#endif //HUFFMAN_STRUCTS_H
