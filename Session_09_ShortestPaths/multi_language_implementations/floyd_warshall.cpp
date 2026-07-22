// Session 09: Floyd-Warshall All-Pairs Shortest Path in C++

#include <iostream>
#include <vector>
#include <iomanip>

#define V 4
#define INF 999999

void runFloydWarshall(int graph[V][V]) {
    int dist[V][V];
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            dist[i][j] = graph[i][j];
        }
    }

    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (dist[i][k] != INF && dist[k][j] != INF && dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    std::cout << "Floyd-Warshall All-Pairs Matrix:\n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INF) {
                std::cout << "  INF";
            } else {
                std::cout << std::setw(5) << dist[i][j];
            }
        }
        std::cout << "\n";
    }
}

int main() {
    int graph[V][V] = {
        {0, 5, INF, 10},
        {INF, 0, 3, INF},
        {INF, INF, 0, 1},
        {INF, INF, INF, 0}
    };
    runFloydWarshall(graph);
    return 0;
}
