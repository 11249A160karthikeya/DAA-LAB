#include <stdio.h>

#define V 3
#define INF 99999

void floyds(int b[V][V]) {
    int i, j, k;

    for (k = 0; k < V; k++) {
        for (i = 0; i < V; i++) {
            for (j = 0; j < V; j++) {
                if (b[i][k] != INF && b[k][j] != INF &&
                    b[i][k] + b[k][j] < b[i][j]) {
                    b[i][j] = b[i][k] + b[k][j];
                }
            }
        }
    }

    printf("All Pairs Shortest Path Matrix:\n");
    for (i = 0; i < V; i++) {
        for (j = 0; j < V; j++) {
            if (b[i][j] == INF)
                printf("INF\t");
            else
                printf("%d\t", b[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int b[V][V] = {
        {0,   10,  INF},
        {INF, 0,   15},
        {12,  INF, 0}
    };

    floyds(b);
    return 0;
}
