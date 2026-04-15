#include <stdio.h>
#include <stdlib.h>

struct Node {
    int v;
    struct Node* next;
};

struct Graph {
    int V;
    struct Node** adj;
};

struct Node* createNode(int v) {
    struct Node* n = malloc(sizeof(struct Node));
    n->v = v;
    n->next = NULL;
    return n;
}

struct Graph* createGraph(int V) {
    struct Graph* g = malloc(sizeof(struct Graph));
    g->V = V;
    g->adj = malloc(V * sizeof(struct Node*));
    for (int i = 0; i < V; i++) g->adj[i] = NULL;
    return g;
}

void addEdge(struct Graph* g, int v, int w) {
    struct Node* n = createNode(w);
    n->next = g->adj[v];
    g->adj[v] = n;
}

void dfs(struct Graph* g, int v, int visited[]) {
    visited[v] = 1;
    printf("%d ", v);

    struct Node* temp = g->adj[v];
    while (temp) {
        if (!visited[temp->v])
            dfs(g, temp->v, visited);
        temp = temp->next;
    }
}

int main() {
    struct Graph* g = createGraph(4);
    addEdge(g, 0, 1);
    addEdge(g, 0, 2);
    addEdge(g, 1, 3);

    int visited[4] = {0};
    dfs(g, 0, visited);
}