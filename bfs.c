#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 50
#define FALSE 0
#define TRUE 1

typedef struct node {
    int vertex;
    struct node* next;
} Node;

Node* graph[MAX_VERTICES];
short int visited[MAX_VERTICES];
int n;

typedef struct queue {
    int vertex;
    struct queue* link;
} QueueNode;

typedef struct queue* queue_pointer;

void addq(queue_pointer* front, queue_pointer* rear, int vertex) {
    queue_pointer temp = (queue_pointer)malloc(sizeof(QueueNode));
    temp->vertex = vertex;
    temp->link = NULL;

    if (*rear) {
        (*rear)->link = temp;
    } else {
        *front = temp;
    }
    *rear = temp;
}

int deleteq(queue_pointer* front) {
    queue_pointer temp = *front;
    int item;

    if (!temp)
        return -1; 

    item = temp->vertex;
    *front = temp->link;
    free(temp);
    return item;
}

Node* createNode(int vertex) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = vertex;
    newNode->next = NULL;
    return newNode;
}

void addEdge(int src, int dest) {
    Node* newNode = createNode(dest);
    newNode->next = graph[src];
    graph[src] = newNode;

    newNode = createNode(src);
    newNode->next = graph[dest];
    graph[dest] = newNode;
}

void bfs(int v) {
    Node* w;
    queue_pointer front = NULL, rear = NULL;

    printf("%5d", v);
    visited[v] = TRUE;
    addq(&front, &rear, v);

    while (front) {
        v = deleteq(&front);
        for (w = graph[v]; w; w = w->next) {
            if (!visited[w->vertex]) {
                printf("%5d", w->vertex);
                visited[w->vertex] = TRUE;
                addq(&front, &rear, w->vertex);
            }
        }
    }
}

int main() {
    int edges;
    int src, dest;
    int startVertex;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        graph[i] = NULL;
        visited[i] = FALSE;
    }

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    printf("Enter each edge (source destination):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &src, &dest);
        addEdge(src, dest);
    }

    printf("Enter the starting vertex for BFS: ");
    scanf("%d", &startVertex);

    printf("\nBFS Traversal:\n");
    bfs(startVertex);
    printf("\n");

    return 0;
}
