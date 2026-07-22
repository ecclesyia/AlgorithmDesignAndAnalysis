#include <stdio.h>
#include <stdlib.h>

/*
 * Session 09: Floyd-Warshall All-Pairs Shortest Path in C
 * Uses dynamic programming with a 2D matrix.
 * Time Complexity: O(V^3)
 * Space Complexity: O(V^2)
 */

#define V 4
#define INF 999999

void printMatrix(int dist[][V]) {
    printf("Shortest distances between every pair of vertices:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INF) {
                printf("%7s", "INF");
            } else {
                printf("%7d", dist[i][j]);
            }
        }
        printf("\n");
    }
}

void runFloydWarshall(int graph[][V]) {
    int dist[V][V];

    // Initialize the solution matrix same as input graph matrix.
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            dist[i][j] = graph[i][j];
        }
    }

    /* Add all vertices one by one to the set of intermediate vertices.
       ---> Before start of an iteration, we have shortest distances between all
            pairs of vertices such that the shortest paths consider only the
            vertices in set {0, 1, ..., k-1} as intermediate vertices.
       ---> After the end of an iteration, vertex k is added to the set of
            intermediate vertices and the set becomes {0, 1, ..., k}. */
    for (int k = 0; k < V; k++) {
        // Pick all vertices as source one by one
        for (int i = 0; i < V; i++) {
            // Pick all vertices as destination for the above picked source
            for (int j = 0; j < V; j++) {
                // If vertex k is on the shortest path from i to j, then update the value of dist[i][j]
                if (dist[i][k] != INF && dist[k][j] != INF && dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    printMatrix(dist);
}

int main() {
    /* Let us create the following weighted graph
            10
       (0)------->(3)
        |         ^
       5|         |1
        v         |
       (1)------->(2)
            3           */
    int graph[V][V] = {
        {0, 5, INF, 10},
        {INF, 0, 3, INF},
        {INF, INF, 0, 1},
        {INF, INF, INF, 0}
    };

    printf("=== Floyd-Warshall All-Pairs Shortest Path ===\n\n");
    runFloydWarshall(graph);

    printf("\nPress Enter to exit...");
    getchar();
    return 0;
}
