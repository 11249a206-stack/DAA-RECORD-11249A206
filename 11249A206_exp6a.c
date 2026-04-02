#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
#define V 6
int min_dist(int dist[], bool visited[]) {
    int minimum = INT_MAX;
    int ind = -1;
    for (int i = 0; i < V; i++) {
        if (!visited[i] && dist[i] < minimum) {
            minimum = dist[i];
            ind = i;
        }
    }
    return ind;
}
void dijkstra(int graph[V][V], int src) {
    int dist[V];
    bool visited[V];
    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        visited[i] = false;
    }
    dist[src] = 0;
    for (int count = 0; count < V - 1; count++) {
        int u = min_dist(dist, visited);
        if (u == -1) break; // No reachable vertex left
        visited[u] = true;
        for (int v = 0; v < V; v++) {
            if (!visited[v] &&
                graph[u][v] != 0 &&
                dist[u] != INT_MAX &&
                dist[u] + graph[u][v] < dist[v]) {

                dist[v] = dist[u] + graph[u][v];
            }
        }
    }
    printf("Vertex\tDistance from Source\n");
    for (int i = 0; i < V; i++) {
        printf("%c\t%d\n", i + 65, dist[i]);
    }
}
int main() {
    int graph[V][V] = {
        {0, 1, 2, 0, 0, 0},
        {1, 0, 0, 5, 1, 0},
        {2, 0, 0, 2, 3, 0},
        {0, 5, 2, 0, 2, 2},
        {0, 1, 3, 2, 0, 1},
        {0, 0, 0, 2, 1, 0}
    };
    dijkstra(graph, 0);
    return 0;
}
