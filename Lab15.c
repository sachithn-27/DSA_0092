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

int bfs(struct Graph* g, int s, int t) {
    int visited[g->V], dist[g->V];
    for (int i = 0; i < g->V; i++) {
        visited[i] = 0;
        dist[i] = -1;
    }

    int q[100], front = 0, rear = 0;
    visited[s] = 1;
    dist[s] = 0;
    q[rear++] = s;

    while (front < rear) {
        int v = q[front++];
        struct Node* temp = g->adj[v];

        while (temp) {
            if (!visited[temp->v]) {
                visited[temp->v] = 1;
                dist[temp->v] = dist[v] + 1;
                q[rear++] = temp->v;
            }
            temp = temp->next;
        }
    }
    return dist[t];
}

int main() {
    struct Graph* g = createGraph(4);
    addEdge(g, 0, 1);
    addEdge(g, 1, 2);
    addEdge(g, 2, 3);

    printf("%d", bfs(g, 0, 3));
}