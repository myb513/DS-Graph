typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

void addEdge(Node** graph, int u, int v);
