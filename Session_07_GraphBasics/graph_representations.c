#include <stdio.h>
#include <stdlib.h>

/*
 * Session 07: Graph Representations in C
 * Shows how to represent a graph using:
 * 1. Adjacency Matrix
 * 2. Adjacency List (dynamic linked list representation)
 */

#define V 4 // Number of vertices

// 1. Adjacency Matrix Representation
void createAdjacencyMatrix(int adjMatrix[V][V]) {
    // Initialize matrix with 0s
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            adjMatrix[i][j] = 0;
        }
    }

    // Add edges
    adjMatrix[0][1] = 1;
    adjMatrix[0][2] = 1;
    adjMatrix[1][3] = 1;
    adjMatrix[3][0] = 1;
}

void printAdjacencyMatrix(int adjMatrix[V][V]) {
    printf("Adjacency Matrix:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            printf("%d ", adjMatrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// 2. Adjacency List Representation
typedef struct AdjListNode {
    int dest;
    struct AdjListNode *next;
} AdjListNode;

typedef struct {
    AdjListNode *head;
} AdjList;

typedef struct {
    int numVertices;
    AdjList *array;
} Graph;

// Create a new adjacency list node
AdjListNode* newAdjListNode(int dest) {
    AdjListNode *newNode = (AdjListNode *)malloc(sizeof(AdjListNode));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}

// Create a graph of V vertices
Graph* createGraph(int numVertices) {
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->numVertices = numVertices;
    graph->array = (AdjList *)malloc(numVertices * sizeof(AdjList));

    for (int i = 0; i < numVertices; i++) {
        graph->array[i].head = NULL;
    }
    return graph;
}

// Add edge to graph (Directed)
void addEdge(Graph *graph, int src, int dest) {
    AdjListNode *newNode = newAdjListNode(dest);
    
    // Insert at head of the list for src
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;
}

void printGraphList(Graph *graph) {
    printf("Adjacency List:\n");
    for (int v = 0; v < graph->numVertices; v++) {
        AdjListNode *curr = graph->array[v].head;
        printf("  Vertex %d: ", v);
        while (curr) {
            printf("-> %d ", curr->dest);
            curr = curr->next;
        }
        printf("-> NULL\n");
    }
    printf("\n");
}

void freeGraph(Graph *graph) {
    for (int v = 0; v < graph->numVertices; v++) {
        AdjListNode *curr = graph->array[v].head;
        while (curr) {
            AdjListNode *temp = curr;
            curr = curr->next;
            free(temp);
        }
    }
    free(graph->array);
    free(graph);
}

int main() {
    printf("=== Graph Representations in C ===\n\n");

    // Adjacency Matrix
    int adjMatrix[V][V];
    createAdjacencyMatrix(adjMatrix);
    printAdjacencyMatrix(adjMatrix);

    // Adjacency List
    Graph *graph = createGraph(V);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 3, 0);
    printGraphList(graph);

    freeGraph(graph);

    printf("Press Enter to exit...");
    getchar();
    return 0;
}
