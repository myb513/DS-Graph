#include "bfs.h"
#include "graph.h"
#include <stdio.h>
#include <stdlib.h>

void bfs(Node** graph, int v, int* visited, int N) {
    int front = 0;
    int rear = 0;
    int queue[1001];

    visited[v] = 1;
    queue[rear++] = v;

    while (front < rear) {
        int vertex = queue[front++];
        printf("%d ", vertex);

        Node* curr = graph[vertex];
        int adj[1001];
        int adjCount = 0;
        while (curr != NULL) {
            adj[adjCount++] = curr->vertex;
            curr = curr->next;
        }
        qsort(adj, adjCount, sizeof(int), cmp);

        for (int i = 0; i < adjCount; i++) {
            int nextVertex = adj[i];
            if (!visited[nextVertex]) {
                queue[rear++] = nextVertex;
                visited[nextVertex] = 1;
            }
        }
    }
}
