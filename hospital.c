#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Patient {
    char name[50];
    int age;
    int priority;
};

struct Node {
    struct Patient data;
    struct Node* next;
};

struct Queue {
    struct Node* front;
    struct Node* rear;
};

void enqueue(struct Queue* q, char* name, int age, int priority) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    strcpy(newNode->data.name, name);
    newNode->data.age = age;
    newNode->data.priority = priority;
    newNode->next = NULL;

    if (q->rear == NULL) {  
        q->front = q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
    printf("Enqueued patient: %s, Age: %d, Priority: %d\n", name, age, priority);
}

void dequeue(struct Queue* q) {
    if (q->front == NULL) {  
        printf("Queue is empty!\n");
        return;
    }

    struct Node* temp = q->front;
    printf("Dequeued patient: %s, Age: %d, Priority: %d\n",
           temp->data.name, temp->data.age, temp->data.priority);

    q->front = q->front->next;
    if (q->front == NULL) {
        q->rear = NULL;
    }

    free(temp);
}
void display(struct Queue* q) {
    if (q->front == NULL) {
        printf("Queue is empty!\n");
        return;
    }

    struct Node* temp = q->front;
    printf("Queue of patients:\n");
    while (temp != NULL) {
        printf("Name: %s, Age: %d, Priority: %d\n",
               temp->data.name, temp->data.age, temp->data.priority);
        temp = temp->next;
    }
    printf("\n");
}
int main() {
    struct Queue* q;
    q->front = NULL;
    q->rear = NULL;
    enqueue(q, "Alice", 30, 2);
    enqueue(q, "Bob", 25, 1);
    enqueue(q, "Charlie", 40, 3);

    display(q);

    dequeue(q);
    display(q);

    return 0;
}
