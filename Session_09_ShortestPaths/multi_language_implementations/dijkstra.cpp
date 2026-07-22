// Session 09: Dijkstra's Single Source Shortest Path in C++

#include <iostream>
#include <vector>

#define V 9
#define INF 999999

int minDistance(const std::vector<int> &dist, const std::vector<bool> &sptSet) {
    int min = INF, min_index = -1;
    for (int v = 0; v < V; v++) {
        if (!sptSet[v] && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

void runDijkstra(int graph[V][V], int src) {
    std::vector<int> dist(V, INF);
    std::vector<bool> sptSet(V, false);

    dist[src] = 0;

    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, sptSet);
        sptSet[u] = true;
        for (int v = 0; v < V; v++) {
            if (!sptSet[v] && graph[u][v] && dist[u] != INF && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    std::cout << "Dijkstra Path distances from " << src << ":\n";
    for (int i = 0; i < V; i++) {
        std::cout << "  Node " << i << ": " << dist[i] << "\n";
    }
}

int main() {
    int graph[V][V] = {
        {0, 4, 0, 0, 0, 0, 0, 8, 0},
        {4, 0, 8, 0, 0, 0, 0, 11, 0},
        {0, 8, 0, 7, 0, 4, 0, 0, 2},
        {0, 0, 7, 0, 9, 14, 0, 0, 0},
        {0, 0, 0, 9, 0, 10, 0, 0, 0},
        {0, 0, 4, 14, 10, 0, 2, 0, 0},
        {0, 0, 0, 0, 0, 2, 0, 1, 6},
        {8, 11, 0, 0, 0, 0, 1, 0, 7},
        {0, 0, 2, 0, 0, 0, 6, 7, 0}
    };
    runDijkstra(graph, 0);
    return 0;
}
