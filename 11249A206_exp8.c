#include <stdio.h>
#define MAX_NODES 100
#define INF 1000000000
int n;
int capacity[MAX_NODES][MAX_NODES];
int flow[MAX_NODES][MAX_NODES];
int parent[MAX_NODES];
int bfs(int source, int sink) {
    int visited[MAX_NODES] = {0};
    int queue[MAX_NODES];
    int front = 0, rear = 0;
    queue[rear++] = source;
    visited[source] = 1;
    parent[source] = -1;
    while (front < rear) {
        int u = queue[front++];
        for (int v = 0; v < n; v++) {
            if (!visited[v] && capacity[u][v] - flow[u][v] > 0) {
                queue[rear++] = v;
                parent[v] = u;
                visited[v] = 1;
                if (v == sink)
                    return 1; 
            }
        }
    }
    return 0;
}
int fordFulkerson(int source, int sink) {
    int max_flow = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            flow[i][j] = 0;
    while (bfs(source, sink)) {
        int path_flow = INF;
        for (int v = sink; v != source; v = parent[v]) {
            int u = parent[v];
            if (capacity[u][v] - flow[u][v] < path_flow)
                path_flow = capacity[u][v] - flow[u][v];
        }
        for (int v = sink; v != source; v = parent[v]) {
            int u = parent[v];
            flow[u][v] += path_flow;
            flow[v][u] -= path_flow;
        }
        max_flow += path_flow;
    }
    return max_flow;
}
int main() {
    n = 6;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            capacity[i][j] = 0;
    capacity[0][1] = 8;
    capacity[0][4] = 3;
    capacity[1][2] = 9;
    capacity[2][4] = 7;
    capacity[2][5] = 2;
    capacity[3][5] = 5;
    capacity[4][2] = 7;
    capacity[4][3] = 4;
    int source = 0, sink = 5;
    printf("Max Flow: %d\n", fordFulkerson(source, sink));
    return 0;
}
