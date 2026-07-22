#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
 * Session 07: BFS and DFS Traversals in C
 * Uses an Adjacency List graph representation to demonstrate:
 * 1. Breadth-First Search (Queue-based)
 * 2. Depth-First Search (Recursive)
 */

typedef struct Node {
    int dest;
    struct Node *next;
} Node;

typedef struct {
    Node *head;
} List;

typedef struct {
    int V;
    List *array;
} Graph;

Graph* createGraph(int vertices) {
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->V = vertices;
    graph->array = (List *)malloc(vertices * sizeof(List));
    for (int i = 0; i < vertices; i++) {
        graph->array[i].head = NULL;
    }
    return graph;
}

// Add undirected edge
void addEdge(Graph *graph, int src, int dest) {
    Node *node1 = (Node *)malloc(sizeof(Node));
    node1->dest = dest;
    node1->next = graph->array[src].head;
    graph->array[src].head = node1;

    Node *node2 = (Node *)malloc(sizeof(Node));
    node2->dest = src;
    node2->next = graph->array[dest].head;
    graph->array[dest].head = node2;
}

// 1. Breadth-First Search (BFS)
// Time Complexity: O(V + E)
// Space Complexity: O(V) for queue and visited array
void runBFS(Graph *graph, int startVertex) {
    bool *visited = (bool *)malloc(graph->V * sizeof(bool));
    for (int i = 0; i < graph->V; i++) visited[i] = false;

    // Simple Queue implementation
    int *queue = (int *)malloc(graph->V * sizeof(int));
    int front = 0, rear = 0;

    visited[startVertex] = true;
    queue[rear++] = startVertex;

    printf("BFS Starting from Vertex %d: ", startVertex);

    while (front < rear) {
        int curr = queue[front++];
        printf("%d ", curr);

        Node *temp = graph->array[curr].head;
        while (temp != NULL) {
            int adj = temp->dest;
            if (!visited[adj]) {
                visited[adj] = true;
                queue[rear++] = adj;
            }
            temp = temp->next;
        }
    }
    printf("\n");

    free(queue);
    free(visited);
}

// Helper recursive function for DFS
void dfsHelper(Graph *graph, int vertex, bool visited[]) {
    visited[vertex] = true;
    printf("%d ", vertex);

    Node *temp = graph->array[vertex].head;
    while (temp != NULL) {
        int adj = temp->dest;
        if (!visited[adj]) {
            dfsHelper(graph, adj, visited);
        }
        temp = temp->next;
    }
}

// 2. Depth-First Search (DFS)
// Time Complexity: O(V + E)
// Space Complexity: O(V) stack call frame space
void runDFS(Graph *graph, int startVertex) {
    bool *visited = (bool *)malloc(graph->V * sizeof(bool));
    for (int i = 0; i < graph->V; i++) visited[i] = false;

    printf("DFS Starting from Vertex %d: ", startVertex);
    dfsHelper(graph, startVertex, visited);
    printf("\n");

    free(visited);
}

void freeGraph(Graph *graph) {
    for (int i = 0; i < graph->V; i++) {
        Node *curr = graph->array[i].head;
        while (curr) {
            Node *temp = curr;
            curr = curr->next;
            free(temp);
        }
    }
    free(graph->array);
    free(graph);
}

int main() {
    int numVertices = 5;
    Graph *graph = createGraph(numVertices);

    // Setup a sample graph:
    // 0 --- 1 --- 3
    // |   /
    // |  /
    // 2 --- 4
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 4);

    printf("=== Graph Search Algorithms ===\n\n");
    runBFS(graph, 0);
    runDFS(graph, 0);

    freeGraph(graph);

    printf("\nPress Enter to exit...");
    getchar();
    return 0;
}
