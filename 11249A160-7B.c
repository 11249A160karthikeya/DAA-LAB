#include <stdio.h>
#include <stdlib.h>

#define V 4   // number of vertices
#define E 5   // number of edges

// Comparator for qsort
int comparator(const void *a, const void *b) {
    return ((int *)a)[2] - ((int *)b)[2];
}

// Initialize DSU
void makeSet(int parent[], int rank[]) {
    for (int i = 0; i < V; i++) {
        parent[i] = i;
        rank[i] = 0;
    }
}

// Find with path compression
int findParent(int parent[], int component) {
    if (parent[component] != component)
        parent[component] = findParent(parent, parent[component]);
    return parent[component];
}

// Union by rank
void unionSet(int u, int v, int parent[], int rank[]) {
    u = findParent(parent, u);
    v = findParent(parent, v);

    if (rank[u] < rank[v]) {
        parent[u] = v;
    } else if (rank[u] > rank[v]) {
        parent[v] = u;
    } else {
        parent[v] = u;
        rank[u]++;
    }
}

// Kruskal Algorithm
int kruskalAlgo(int edge[E][3]) {
    qsort(edge, E, sizeof(edge[0]), comparator);

    int parent[V], rank[V];
    makeSet(parent, rank);

    int minCost = 0;

    printf("Edges in MST:\n");

    for (int i = 0; i < E; i++) {
        int u = edge[i][0];
        int v = edge[i][1];
        int wt = edge[i][2];

        int setU = findParent(parent, u);
        int setV = findParent(parent, v);

        if (setU != setV) {
            printf("%d - %d : %d\n", u, v, wt);
            minCost += wt;
            unionSet(setU, setV, parent, rank);
        }
    }

    return minCost;
}

int main() {
    int edge[E][3] = {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4}
    };

    int cost = kruskalAlgo(edge);
    printf("Minimum Cost = %d\n", cost);

    return 0;
}
