#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* left;
    struct node* right;
};
struct node* create() {
    int val;
    printf("Enter data: ");
    scanf("%d", &val);

    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = val;

    printf("Enter left child of %d:\n", val);
    newNode->left = create();

    printf("Enter right child of %d:\n", val);
    newNode->right = create();

    return newNode;
}
void levelOrder(struct node* root) {
    if (root == NULL) return;

    struct node* queue[100];
    int front = 0, rear = 0;
    queue[rear++] = root;

    while (front < rear) {
        struct node* curr = queue[front++];
        printf("%d ", curr->data);

        if (curr->left != NULL)
            queue[rear++] = curr->left;
        if (curr->right != NULL)
            queue[rear++] = curr->right;
    }
}
