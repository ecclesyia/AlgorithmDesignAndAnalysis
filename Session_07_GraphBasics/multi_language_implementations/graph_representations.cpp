// Session 07: Graph Representations in C++
// Shows how to represent a graph using:
// 1. Adjacency Matrix
// 2. Adjacency List

#include <iostream>
#include <vector>

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
    std::cout << "Adjacency Matrix:\n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            std::cout << adjMatrix[i][j] << " ";
        }
        std::cout << "\n";
    }
    std::cout << "\n";
}

// 2. Adjacency List Representation
struct AdjListNode {
    int dest;
    AdjListNode *next;
    AdjListNode(int d) : dest(d), next(nullptr) {}
};

struct AdjList {
    AdjListNode *head;
    AdjList() : head(nullptr) {}
};

class Graph {
public:
    int numVertices;
    std::vector<AdjList> array;

    Graph(int V) : numVertices(V), array(V) {}

    ~Graph() {
        for (int i = 0; i < numVertices; i++) {
            AdjListNode *curr = array[i].head;
            while (curr != nullptr) {
                AdjListNode *temp = curr;
                curr = curr->next;
                delete temp;
            }
        }
    }

    // Add edge to graph (Directed)
    void addEdge(int src, int dest) {
        AdjListNode *newNode = new AdjListNode(dest);
        
        // Insert at head of the list for src
        newNode->next = array[src].head;
        array[src].head = newNode;
    }
};

void printGraphList(Graph &graph) {
    std::cout << "Adjacency List:\n";
    for (int v = 0; v < graph.numVertices; v++) {
        AdjListNode *curr = graph.array[v].head;
        std::cout << "  Vertex " << v << ": ";
        while (curr != nullptr) {
            std::cout << "-> " << curr->dest << " ";
            curr = curr->next;
        }
        std::cout << "-> NULL\n";
    }
    std::cout << "\n";
}

int main() {
    // Adjacency Matrix
    int adjMatrix[V][V];
    createAdjacencyMatrix(adjMatrix);
    printAdjacencyMatrix(adjMatrix);

    // Adjacency List
    Graph graph(V);
    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 3);
    graph.addEdge(3, 0);
    printGraphList(graph);

    return 0;
}
