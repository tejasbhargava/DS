#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

typedef struct node {
    int vertex;
    struct node* next;
} Node;

Node* graph[MAX_VERTICES];

int n = 0;

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

void displayGraph() {
    for (int i = 0; i < n; i++) {
        Node* temp = graph[i];
        printf("Vertex %d: ", i);
        while (temp) {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main() {
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        graph[i] = NULL;
    }

    int edges;
    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    printf("Enter each edge (source destination):\n");
    for (int i = 0; i < edges; i++) {
        int src, dest;
        scanf("%d %d", &src, &dest);
        addEdge(src, dest);
    }

    printf("\nAdjacency List Representation:\n");
    displayGraph();

    return 0;
}
