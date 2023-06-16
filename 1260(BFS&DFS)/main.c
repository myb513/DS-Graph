#include "graph.h"
#include "dfs.h"
#include "bfs.h"
#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

int main() {
    int N, M, V;
    scanf("%d %d %d", &N, &M, &V);

    Node** graph = (Node**)malloc((N + 1) * sizeof(Node*));
    for (int i = 0; i <= N; i++) {
        graph[i] = NULL;
    }

    int u, v;
    for (int i = 0; i < M; i++) {
        scanf("%d %d", &u, &v);
        addEdge(graph, u, v);
    }

    int* visited = (int*)calloc(N + 1, sizeof(int));

    dfs(graph, V, visited);
    printf("\n");

    for (int i = 0; i <= N; i++) {
        visited[i] = 0;
    }

    bfs(graph, V, visited, N);
    printf("\n");

    for (int i = 0; i <= N; i++) {
        Node* curr = graph[i];
        while (curr != NULL) {
            Node* temp = curr;
            curr = curr->next;
            free(temp);
        }
    }
    free(graph);
    free(visited);

    return 0;
}
