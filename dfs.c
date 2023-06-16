#include "dfs.h"
#include "graph.h"
#include <stdio.h>
#include <stdlib.h>

int cmp(const void* a, const void* b) {
    return (*(int*)a) - (*(int*)b);
}

void dfs(Node** graph, int v, int* visited) {
    visited[v] = 1;
    printf("%d ", v);

    Node* curr = graph[v];
    int adj[1001];
    int adjCount = 0;
    while (curr != NULL) {
        adj[adjCount++] = curr->vertex;
        curr = curr->next;
    }
    qsort(adj, adjCount, sizeof(int), cmp);

    for (int i = 0; i < adjCount; i++) {
        int vertex = adj[i];
        if (!visited[vertex]) {
            dfs(graph, vertex, visited);
        }
    }
}
