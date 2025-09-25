#include<stdio.h>

struct queue{
    int data[10];
    int front;
    int rear;
};
void enqueue(struct queue* q, int val){
    if((q->rear + 1) % 10 == q->front){
        printf("full");
        return;
    }
    if(q->front == -1 && q->rear == -1){
        q->front = 0;
        q->rear = 0;
    }
    else{
        q->rear = (q->rear + 1)  % 10;
    }
    q->data[q->rear] = val;
    return;
}
int dequeue(struct queue* q){
    
    if(q->front == -1 && q->rear == -1){
        printf("empty");
        return -1;
    }
    int popped = q->data[q->front];
    if(q->front == q->rear){
        q->front = -1;
        q->rear = -1;
        
        return popped;
    }
    q->front = (q->front + 1) % 10;
    return popped;
}
void display(struct queue* q){
    int i = q->front;
    while(i != q->rear){
        printf("%d ", q->data[i]);
        i = (i + 1) % 10;
    }
    printf("%d", q->data[q->rear]);
    printf("\n");
}

int main(){
    struct queue* q;
    q->front = -1;
    q->rear = -1;
    enqueue(q, 10);
    display(q);
    enqueue(q, 20);
    display(q);
    enqueue(q, 30);
    display(q);
    dequeue(q);
    display(q);
    return 0;
}