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

void greedy_dijkstra(int graph[V][V], int src) {
    int dist[V];
    bool visited[V];

    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        visited[i] = false;
    }

    dist[src] = 0;

    for (int count = 0; count < V - 1; count++) {
        int m = min_dist(dist, visited);

        if (m == -1) break; // safety check

        visited[m] = true;

        for (int i = 0; i < V; i++) {
            if (!visited[i] && graph[m][i] &&
                dist[m] != INT_MAX &&
                dist[m] + graph[m][i] < dist[i]) {
                dist[i] = dist[m] + graph[m][i];
            }
        }
    }

    printf("Vertex\tDistance from Source\n");
    for (int i = 0; i < V; i++) {
        printf("%c\t%d\n", 'A' + i, dist[i]);
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

    greedy_dijkstra(graph, 0);
    return 0;
}
