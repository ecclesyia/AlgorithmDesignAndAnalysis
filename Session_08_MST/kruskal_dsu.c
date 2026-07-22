#include <stdio.h>
#include <stdlib.h>

/*
 * Session 08: Kruskal's MST Algorithm in C
 * Uses a Disjoint Set Union (DSU) structure to check for cycles.
 * Time Complexity: O(E log E) or O(E log V)
 * Space Complexity: O(V + E)
 */

typedef struct {
    int src, dest, weight;
} Edge;

typedef struct {
    int V, E;
    Edge *edges;
} Graph;

typedef struct {
    int parent;
    int rank;
} Subset;

Graph* createGraph(int V, int E) {
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->V = V;
    graph->E = E;
    graph->edges = (Edge *)malloc(E * sizeof(Edge));
    return graph;
}

// DSU: Find operation with Path Compression
int find(Subset subsets[], int i) {
    if (subsets[i].parent != i) {
        subsets[i].parent = find(subsets, subsets[i].parent);
    }
    return subsets[i].parent;
}

// DSU: Union operation by Rank
void Union(Subset subsets[], int x, int y) {
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    if (subsets[xroot].rank < subsets[yroot].rank) {
        subsets[xroot].parent = yroot;
    } else if (subsets[xroot].rank > subsets[yroot].rank) {
        subsets[yroot].parent = xroot;
    } else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

// Comparison function for sorting edges by weight
int compareEdges(const void *a, const void *b) {
    Edge *edgeA = (Edge *)a;
    Edge *edgeB = (Edge *)b;
    return edgeA->weight - edgeB->weight;
}

void runKruskal(Graph *graph) {
    int V = graph->V;
    Edge *result = (Edge *)malloc((V - 1) * sizeof(Edge));
    int e = 0; // Index for result[]
    int i = 0; // Index for sorted edges[]

    // 1. Sort all edges
    qsort(graph->edges, graph->E, sizeof(Edge), compareEdges);

    // Allocate memory for subsets
    Subset *subsets = (Subset *)malloc(V * sizeof(Subset));
    for (int v = 0; v < V; v++) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    printf("Kruskal's Edge Evaluation:\n");

    // Number of edges to be taken is V-1
    while (e < V - 1 && i < graph->E) {
        Edge nextEdge = graph->edges[i++];

        int x = find(subsets, nextEdge.src);
        int y = find(subsets, nextEdge.dest);

        // If including this edge doesn't cause cycle, include it
        if (x != y) {
            result[e++] = nextEdge;
            Union(subsets, x, y);
            printf("  Accepted edge: %d - %d (weight: %d)\n", 
                   nextEdge.src, nextEdge.dest, nextEdge.weight);
        } else {
            printf("  Rejected edge: %d - %d (weight: %d) -> forms a cycle\n", 
                   nextEdge.src, nextEdge.dest, nextEdge.weight);
        }
    }

    printf("\nFinal Minimum Spanning Tree Edges:\n");
    int minimumCost = 0;
    for (i = 0; i < e; i++) {
        printf("  %d - %d == %d\n", result[i].src, result[i].dest, result[i].weight);
        minimumCost += result[i].weight;
    }
    printf("Total Cost of MST: %d\n", minimumCost);

    free(subsets);
    free(result);
}

int main() {
    int V = 4; // Number of vertices
    int E = 5; // Number of edges
    Graph *graph = createGraph(V, E);

    // Add edge 0-1
    graph->edges[0].src = 0;
    graph->edges[0].dest = 1;
    graph->edges[0].weight = 10;

    // Add edge 0-2
    graph->edges[1].src = 0;
    graph->edges[1].dest = 2;
    graph->edges[1].weight = 6;

    // Add edge 0-3
    graph->edges[2].src = 0;
    graph->edges[2].dest = 3;
    graph->edges[2].weight = 5;

    // Add edge 1-3
    graph->edges[3].src = 1;
    graph->edges[3].dest = 3;
    graph->edges[3].weight = 15;

    // Add edge 2-3
    graph->edges[4].src = 2;
    graph->edges[4].dest = 3;
    graph->edges[4].weight = 4;

    printf("=== Kruskal's Minimum Spanning Tree ===\n\n");
    runKruskal(graph);

    free(graph->edges);
    free(graph);

    printf("\nPress Enter to exit...");
    getchar();
    return 0;
}
