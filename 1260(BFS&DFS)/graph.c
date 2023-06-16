#include "graph.h"
#include <stdlib.h>

void addEdge(Node** graph, int u, int v) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = graph[u];
    graph[u] = newNode;

    newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = u;
    newNode->next = graph[v];
    graph[v] = newNode;
}
