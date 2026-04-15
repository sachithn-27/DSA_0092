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

    n = createNode(v);
    n->next = g->adj[w];
    g->adj[w] = n;
}

int dfs(struct Graph* g, int v, int visited[], int parent) {
    visited[v] = 1;
    struct Node* temp = g->adj[v];

    while (temp) {
        if (!visited[temp->v]) {
            if (dfs(g, temp->v, visited, v)) return 1;
        } else if (temp->v != parent) {
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}

int hasCycle(struct Graph* g) {
    int visited[g->V];
    for (int i = 0; i < g->V; i++) visited[i] = 0;

    for (int i = 0; i < g->V; i++)
        if (!visited[i])
            if (dfs(g, i, visited, -1)) return 1;

    return 0;
}

int main() {
    struct Graph* g = createGraph(3);
    addEdge(g, 0, 1);
    addEdge(g, 1, 2);
    addEdge(g, 2, 0);

    printf("%d", hasCycle(g));
}