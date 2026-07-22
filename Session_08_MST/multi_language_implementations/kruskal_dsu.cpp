// Session 08: Kruskal's Algorithm with Disjoint Set Union in C++

#include <iostream>
#include <vector>
#include <algorithm>

struct Edge {
    int src, dest, weight;
};

struct Graph {
    int V, E;
    std::vector<Edge> edges;
};

struct Subset {
    int parent, rank;
};

int find(std::vector<Subset> &subsets, int i) {
    if (subsets[i].parent != i) {
        subsets[i].parent = find(subsets, subsets[i].parent);
    }
    return subsets[i].parent;
}

void Union(std::vector<Subset> &subsets, int x, int y) {
    int xr = find(subsets, x);
    int yr = find(subsets, y);
    if (subsets[xr].rank < subsets[yr].rank) {
        subsets[xr].parent = yr;
    } else if (subsets[xr].rank > subsets[yr].rank) {
        subsets[yr].parent = xr;
    } else {
        subsets[yr].parent = xr;
        subsets[xr].rank++;
    }
}

bool compareEdges(const Edge &a, const Edge &b) {
    return a.weight < b.weight;
}

void runKruskal(Graph &graph) {
    int V = graph.V;
    std::vector<Edge> result(V - 1);
    int e = 0;
    int i = 0;

    std::sort(graph.edges.begin(), graph.edges.end(), compareEdges);

    std::vector<Subset> subsets(V);
    for (int v = 0; v < V; v++) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    while (e < V - 1 && i < graph.E) {
        Edge nextEdge = graph.edges[i++];
        int x = find(subsets, nextEdge.src);
        int y = find(subsets, nextEdge.dest);
        if (x != y) {
            result[e++] = nextEdge;
            Union(subsets, x, y);
        }
    }

    std::cout << "Kruskal MST Edges:\n";
    int cost = 0;
    for (i = 0; i < e; i++) {
        std::cout << "  " << result[i].src << " - " << result[i].dest << " == " << result[i].weight << "\n";
        cost += result[i].weight;
    }
    std::cout << "Total Cost: " << cost << "\n";
}

int main() {
    Graph graph;
    graph.V = 4;
    graph.E = 5;
    graph.edges.push_back({0, 1, 10});
    graph.edges.push_back({0, 2, 6});
    graph.edges.push_back({0, 3, 5});
    graph.edges.push_back({1, 3, 15});
    graph.edges.push_back({2, 3, 4});

    runKruskal(graph);

    return 0;
}
