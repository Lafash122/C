#ifndef LAB6_0_TREE_H
#define LAB6_0_TREE_H

#include <malloc.h>
#include <stdio.h>

#define avl struct tree

//The description of avl-tree structure
avl{
    int value;
    struct tree *right;
    struct tree *left;
};

//The function of creation of the tree
avl *create(int value) {
    avl *root = (avl *) malloc(sizeof(avl));
    root->value = value;
    root->right = NULL;
    root->left = NULL;

    return root;
}

//The function of searching the maximum element
int max(int a, int b) {
    if (a > b)
        return a;
    return b;
}

//The function of height of the tree
int height(avl *t) {
    if (!t)
        return 0;
    return max(height(t->right), height(t->left)) + 1;
}

//The function that count the difference of right and left trees
int heightdif(avl *t) {
    return height(t->right) - height(t->left);
}

//The function of the small right rotation
avl *srr(avl *t) {
    avl *root = t->left;
    t->left = root->right;
    root->right = t;

    return root;
}

//The function of the small left rotation
avl *slr(avl *t) {
    avl *root = t->right;
    t->right = root->left;
    root->left = t;

    return root;
}

//The function of balancing the tree
avl *balance(avl *t) {

    if (heightdif(t) == 2) {
        if (heightdif(t->right) < 0)
            t->right = srr(t->right);
        return slr(t);
    }

    if (heightdif(t) == -2) {
        if (heightdif(t->left) > 0)
            t->left = slr(t->left);
        return srr(t);
    }

    return t;
}

//The function of addition a new element
avl *add(avl *t, int val) {
    if (!t)
        return create(val);

    else
    if (val < t->value)
        t->left = add(t->left, val);
    else
        t->right = add(t->right, val);

    return balance(t);
}

//The searching of the element
void search(avl *t, int val) {
    if (val == t->value) {
        printf("Found it");
        return;
    }
    if (val > t->value)
        search(t->right, val);
    search(t->left, val);
    printf("Not found it");
}

//The function of infix form print
void inorder(avl *t) {
    if (t->left)
        inorder(t->left);
    printf("%d ", t->value);
    if (t->right)
        inorder(t->right);
}

//The function of prefix form print
void preorder(avl *t) {
    printf("%d ", t->value);
    if (t->left)
        preorder(t->left);
    if (t->right)
        preorder(t->right);
}

//The function of postfix form print
void postorder(avl *t) {
    if (t->left)
        postorder(t->left);
    if (t->right)
        postorder(t->right);
    printf("%d ", t->value);
}

#endif //LAB6_0_TREE_H
