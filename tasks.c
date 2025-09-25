#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Job {
    int docID;
    char docName[50];
};
struct queue{
    struct Job jobs[10];
    int front;
    int rear;
};
void enqueue(struct queue* q, int id, char* name){
    if (q->rear == 10) {
        printf("Queue is full! Cannot add new job.\n");
        return;
    }
    ++q->rear;
    q->jobs[q->rear].docID = id;
    strcpy(q->jobs[q->rear].docName, name);

    printf("Enqueued: Job ID %d, Name: %s\n", id, name);
}
void dequeue(struct queue* q){
    
    if (q->front == -1 && q->rear == -1) {
        printf("Queue is empty! No jobs to print.\n");
        return;
    }

    struct Job job = q->jobs[q->front];
    printf("Printing: Job ID %d, Name: %s\n", job.docID, job.docName);

    q->front++;
}
int main(){
    struct queue* q;
    q->front = -1;
    q->rear = -1;
    enqueue(q, 1, "Doc_A");
    enqueue(q, 2, "Doc_B");
    dequeue(q);
    dequeue(q);
    enqueue(q, 3, "Doc_C");
    return 0;
}