#include <stdio.h>
#include <stdlib.h>
#define V 4   
#define E 5   
int comparator(const void *a, const void *b) {
    return ((int *)a)[2] - ((int *)b)[2];
}
void makeSet(int parent[], int rank[]) {
    for (int i = 0; i < V; i++) {
        parent[i] = i;
        rank[i] = 0;
    }
}
int findParent(int parent[], int i) {
    if (parent[i] != i)
        parent[i] = findParent(parent, parent[i]);
    return parent[i];
}
void unionSet(int u, int v, int parent[], int rank[]) {
    u = findParent(parent, u);
    v = findParent(parent, v);
    if (rank[u] < rank[v])
        parent[u] = v;
    else if (rank[u] > rank[v])
        parent[v] = u;
    else {
        parent[v] = u;
        rank[u]++;
    }
}
int kruskalAlgo(int edges[E][3]) {
    qsort(edges, E, sizeof(edges[0]), comparator);
    int parent[V], rank[V];
    makeSet(parent, rank);
    int minCost = 0;
    printf("Edge \tWeight\n");
    for (int i = 0; i < E; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        int wt = edges[i][2];
        int set_u = findParent(parent, u);
        int set_v = findParent(parent, v);
        if (set_u != set_v) {
            printf("%d - %d \t%d\n", u, v, wt);
            minCost += wt;
            unionSet(set_u, set_v, parent, rank);
        }
    }
    return minCost;
}
int main() {
    int edges[E][3] = {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4}
    };
    int cost = kruskalAlgo(edges);
    printf("Minimum Cost = %d\n", cost);
    return 0;
}
