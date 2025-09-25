#include<stdio.h>
#include<stdlib.h>

struct node{
    struct node* next;
    int data;
};

struct queue{
    struct node* front;
    struct node* rear;
};

void enqueue(struct queue* q, int val){
    struct node* newnode = (struct node*) malloc(sizeof(struct node));
    newnode->data = val;
    newnode->next = NULL;

    if(q->front == NULL && q->rear == NULL){
        q->front = newnode;
        q->rear = newnode;
        return;
    } 
    q->rear->next = newnode;
    q->rear = newnode;
    return;
}
void dequeue(struct queue* q){
    if(q->front == NULL && q->rear == NULL){
        printf("empty");
        return ;
    }
    if(q->front == q->rear){
        q->front = NULL;
        q->rear = NULL;
    }
    struct node* temp = q->front;
    q->front = q->front->next;
    free(temp);
}
void dsiplay(struct queue* q){

    struct node* temp = q->front;
    while(temp != NULL){
        printf("%d", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
int main(){
    struct queue* q;
    q->front = NULL;
    q->rear = NULL;
    enqueue(q, 10);
    dsiplay(q);
    enqueue(q, 20);
    dsiplay(q);
    enqueue(q, 30);
    dsiplay(q);
    dequeue(q);
    dsiplay(q);
    dequeue(q);
    dsiplay(q);
}
