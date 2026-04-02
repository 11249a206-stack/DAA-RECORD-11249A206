#include <stdio.h>
#include <limits.h>
#define V 6
int graph[V][V] = {
    {0, 10, 0, 15, 0, 0},
    {0, 0, 0, 5, 10, 0},
    {0, 0, 0, 0, 0, 10},
    {0, 0, 0, 0, 0, 5},
    {0, 0, 0, 0, 0, 10},
    {0, 0, 0, 0, 0, 0}
};
void bellman_ford(int source) {
    int distance[V];
    for (int i = 0; i < V; i++) {
        distance[i] = INT_MAX;
    }
    distance[source] = 0;
    for (int i = 0; i < V - 1; i++) {
        for (int u = 0; u < V; u++) {
            for (int v = 0; v < V; v++) {
                if (graph[u][v] != 0 &&
                    distance[u] != INT_MAX &&
                    distance[u] + graph[u][v] < distance[v]) {
                    distance[v] = distance[u] + graph[u][v];
                }
            }
        }
    }
    for (int u = 0; u < V; u++) {
        for (int v = 0; v < V; v++) {
            if (graph[u][v] != 0 &&
                distance[u] != INT_MAX &&
                distance[u] + graph[u][v] < distance[v]) {
                printf("Graph contains negative weight cycle\n");
                return;
            }
        }
    }
    printf("Vertex\tDistance from Source\n");
    for (int i = 0; i < V; i++) {
        if (distance[i] == INT_MAX)
            printf("%d\tINF\n", i);
        else
            printf("%d\t%d\n", i, distance[i]);
    }
}
int main() {
    bellman_ford(0);
    return 0;
}
