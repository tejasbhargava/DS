#include<stdio.h>
#include<stdlib.h>

struct node{
    struct node* left;
    struct node* right;
    int data;
};
struct stack {
    int top;
    struct node* data[10];
};

void push(struct stack* s, struct node* node) {
    if (s->top >= 9) {
        printf("Exceeded capacity\n");
        return;
    }
    s->top++;
    s->data[s->top] = node;
}

struct node* pop(struct stack* s) {
    if (s->top == -1) {
        printf("Empty stack\n");
        return; 
    }
    struct node* popped = s->data[s->top];
    s->top--;
    return popped;
}
int isEmpty(struct stack* s){
    if(s->top == -1) return 1;
    return 0;
}
void inorder(struct node* node){
    struct stack* s = (struct stack*)malloc(sizeof(struct stack));
    s->top = -1;
    while(node != NULL || !isEmpty(s)){
        if(node != NULL){
            push(s, node);
            node = node->left;
        }
        else{
            node = pop(s);
            printf("%d", node->data);
            node = node->right;
        }
    }
}
void postOrder(struct node* node){
    struct stack* s1 = (struct stack*)malloc(sizeof(struct stack));
    struct stack* s2 = (struct stack*)malloc(sizeof(struct stack));
    s1->top = -1;
    s2->top = -1;
    push(s1, node);
    while(isEmpty(s1) != 1){
        node = pop(s1);
        push(s2, node);
        if(node->left != NULL){
            push(s1, node->left);
        }
        if(node->right != NULL){
            push(s1, node->right);
        }
    }
    while(isEmpty(s2) != 1){
        struct node* popped = pop(s2);
        printf("%d ", popped->data);
    }
}
void preOrder(struct node* node){
    struct stack* s = (struct stack*)malloc(sizeof(struct stack));
    s->top = -1;
    push(s, node);
    while(isEmpty(s) != 1){
        struct node* popped = pop(s);
        printf("%d ", popped->data);
        if(popped->right != NULL){
            push(s, node->right);
        }
        if(popped->left != NULL){
            push(s, node->left);
        }
    }
}
void parent(struct node* node, int val){
    if(node->data == val){
        printf("root no parent");
        return;
    }
    if(node == NULL) return; 
    if(node->left != NULL && node->left->data == val || node->right != NULL && node->right->data == val){
        printf("parent is: %d ", node->data);
        return;
    }
    else{
        parent(node->left, val);
        parent(node->right, val);
    }
}
int max(int a, int b) {
    if (a > b) {
        return a;
    } else {
        return b;
    }
}
int height(struct node* node){
    if(node == NULL) return 0;
    int left = height(node->left);
    int right = height(node->right);
    return 1 + max(left, right);
}
int ancestors(struct node* node, int val){
    if(node == NULL){
        return 0;
    }
    if(node->data == val){
        return 1;
    }
    if(ancestors(node->left, val) == 1 || ancestors(node->right, val) == 1){
        printf("%d ", node->data);
        return 1;
    }
    return 0;
}
int leafNode(struct node* node){
    if(node == NULL) return 0;
    if(node->left == NULL && node->right == NULL){
        return 1;
    }
    int left = leafNode(node->left);
    int right = leafNode(node->right);
    return left + right;
}