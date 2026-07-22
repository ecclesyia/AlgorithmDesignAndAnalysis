// Session 08: Prim's Minimum Spanning Tree (MST) in C++

#include <iostream>
#include <vector>

#define V 5
#define INF 999999

int minKey(const std::vector<int> &key, const std::vector<bool> &mstSet) {
    int min = INF, min_index = -1;
    for (int v = 0; v < V; v++) {
        if (!mstSet[v] && key[v] < min) {
            min = key[v];
            min_index = v;
        }
    }
    return min_index;
}

void runPrim(int graph[V][V]) {
    std::vector<int> parent(V);
    std::vector<int> key(V, INF);
    std::vector<bool> mstSet(V, false);

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < V - 1; count++) {
        int u = minKey(key, mstSet);
        mstSet[u] = true;
        for (int v = 0; v < V; v++) {
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    std::cout << "Prim's MST:\n";
    int cost = 0;
    for (int i = 1; i < V; i++) {
        std::cout << "  " << parent[i] << " - " << i << " == " << graph[i][parent[i]] << "\n";
        cost += graph[i][parent[i]];
    }
    std::cout << "Total Cost: " << cost << "\n";
}

int main() {
    int graph[V][V] = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };
    runPrim(graph);
    return 0;
}
