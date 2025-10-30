#include <stdio.h>

#define MAX 100

void createGraph(int adj[MAX][MAX], int vertices, int edges, int directed) {
    int i, u, v;
    
    for (i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            adj[i][j] = 0;
        }
    }

    printf("Enter edges (u v) one by one (0-indexed):\n");
    for (i = 0; i < edges; i++) {
        scanf("%d%d", &u, &v);
        adj[u][v] = 1;
        if (!directed)
            adj[v][u] = 1; 
    }
}

void printGraph(int adj[MAX][MAX], int vertices) {
    printf("\nAdjacency Matrix:\n");
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            printf("%d ", adj[i][j]);
        }
        printf("\n");
    }
}
