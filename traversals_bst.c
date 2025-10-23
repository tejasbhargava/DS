#include<stdio.h>
struct node{
    int data;
    struct node* left;
    struct node* right;
};
struct stack {
    int top;
    struct node* data[1000];
};
void push(struct stack* s, struct node* node) {
    if (s->top >= 999) {
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
struct node* insert(struct node* root, int val){
    if(root == NULL){
        struct node* newnode = (struct node*)malloc(sizeof(struct node));
        newnode->data = val;
        newnode->left = NULL;
        newnode->right = NULL;
        return newnode;
    }
    if(val < root->data){
        root->left = insert(root->left, val);
    }
    else if(val > root->data){
        root->right = insert(root->right, val);
    }
    return root;
}
struct node* search(struct node* root, int val){
    if(root == NULL) return NULL;
    if(root->data == val){
        return root;
    }
    if(root->data > val){
        root = search(root->left, val);
    }
    else if(root->data < val){
        root = search(root->right, val);
    }
    return root;
}
void delete(struct node** root, int val){
    struct node* curr = *root;
    struct node* parent = NULL;
    struct node* q = NULL;
    struct node* succ;
    struct node* succParent;
    while(curr != NULL && curr->data != val){
        if(curr->data > val){
            parent = curr;
            curr = curr->left;
        }
        else if(curr->data < val){
            parent = curr;
            curr = curr->right;
        }
    }
    if(curr == NULL){
        printf("not found");
        return;
    } 
    if(curr->left == NULL) q = curr->right;
    else if(curr->right == NULL) q = curr->left;
    else{
        succParent = curr;
        succ = curr->right;
        while(succ->left != NULL){
            succParent = succ;
            succ = succ->left;
        }
        curr->data = succ->data;
        parent = succParent;
        curr = succ;
        q = curr->right;
    }
    if(parent == NULL){
        *root = q;
        free(curr);
        return;
    }
    if(curr == parent->left) parent->left = q;
    else parent->right = q;
    free(curr);
    return;
}
void minMax(struct node* root){
    if (root == NULL) {
        printf("Tree is empty\n");
        return;
    }
    int min;
    int max;
    struct node* lc = root;
    struct node* rc = root;
    while(lc != NULL){
        min = lc->data;
        lc = lc->left;
        
    }
    while(rc != NULL){
        max = rc->data;
        rc = rc->right;
    }
    printf("min and max are %d %d", min, max);
}