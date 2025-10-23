#include <stdio.h>
#include <stdlib.h>

#define MAX(a,b) ((a) > (b) ? (a) : (b))

typedef struct AvlNode {
    int element;
    struct AvlNode *left;
    struct AvlNode *right;
    int height;
} AvlNode;

int height(AvlNode *t) {
    return t == NULL ? -1 : t->height;
}

void rotateWithLeftChild(AvlNode **k2) {
    AvlNode *k1 = (*k2)->left;
    (*k2)->left = k1->right;
    k1->right = *k2;

    (*k2)->height = MAX(height((*k2)->left), height((*k2)->right)) + 1;
    k1->height = MAX(height(k1->left), (*k2)->height) + 1;

    *k2 = k1;
}

void rotateWithRightChild(AvlNode **k1) {
    AvlNode *k2 = (*k1)->right;
    (*k1)->right = k2->left;
    k2->left = *k1;

    (*k1)->height = MAX(height((*k1)->left), height((*k1)->right)) + 1;
    k2->height = MAX(height(k2->right), (*k1)->height) + 1;

    *k1 = k2;
}

void doubleWithLeftChild(AvlNode **k3) {
    rotateWithRightChild(&((*k3)->left));
    rotateWithLeftChild(k3);
}

void doubleWithRightChild(AvlNode **k3) {
    rotateWithLeftChild(&((*k3)->right));
    rotateWithRightChild(k3);
}

void insert(int x, AvlNode **t) {
    if (*t == NULL) {
        *t = (AvlNode*)malloc(sizeof(AvlNode));
        (*t)->element = x;
        (*t)->left = (*t)->right = NULL;
        (*t)->height = 0;
    } 
    else if (x < (*t)->element) {
        insert(x, &((*t)->left));
        if (height((*t)->left) - height((*t)->right) == 2) {
            if (x < (*t)->left->element)
                rotateWithLeftChild(t);
            else
                doubleWithLeftChild(t);
        }
    } 
    else if (x > (*t)->element) {
        insert(x, &((*t)->right));
        if (height((*t)->right) - height((*t)->left) == 2) {
            if (x > (*t)->right->element)
                rotateWithRightChild(t);
            else
                doubleWithRightChild(t);
        }
    }

    (*t)->height = MAX(height((*t)->left), height((*t)->right)) + 1;
}

void inorder(AvlNode *t) {
    if (t != NULL) {
        inorder(t->left);
        printf("%d ", t->element);
        inorder(t->right);
    }
}

int main() {
    AvlNode *root = NULL;
    int arr[] = {30, 20, 40, 10, 25, 35, 50, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < n; i++) {
        insert(arr[i], &root);
    }

    printf("Inorder traversal of AVL tree:\n");
    inorder(root);
    printf("\n");

    return 0;
}
