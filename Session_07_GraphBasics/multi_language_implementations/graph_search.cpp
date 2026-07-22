// Session 07: BFS and DFS Traversals in C++
// Uses an Adjacency List graph representation to demonstrate:
// 1. Breadth-First Search (Queue-based)
// 2. Depth-First Search (Recursive)

#include <iostream>
#include <vector>
#include <queue>

struct Node {
    int dest;
    Node *next;
    Node(int dest) : dest(dest), next(nullptr) {}
};

class Graph {
public:
    int V;
    std::vector<Node*> headArray;

    Graph(int vertices) : V(vertices), headArray(vertices, nullptr) {}

    ~Graph() {
        for (int i = 0; i < V; i++) {
            Node *curr = headArray[i];
            while (curr != nullptr) {
                Node *temp = curr;
                curr = curr->next;
                delete temp;
            }
        }
    }

    // Add undirected edge
    void addEdge(int src, int dest) {
        Node *node1 = new Node(dest);
        node1->next = headArray[src];
        headArray[src] = node1;

        Node *node2 = new Node(src);
        node2->next = headArray[dest];
        headArray[dest] = node2;
    }
};

// 1. Breadth-First Search (BFS)
void runBFS(Graph &graph, int startVertex) {
    std::vector<bool> visited(graph.V, false);
    std::vector<int> q(graph.V);
    int front = 0, rear = 0;

    visited[startVertex] = true;
    q[rear++] = startVertex;

    std::cout << "BFS: ";
    while (front < rear) {
        int curr = q[front++];
        std::cout << curr << " ";

        Node *temp = graph.headArray[curr];
        while (temp != nullptr) {
            int adj = temp->dest;
            if (!visited[adj]) {
                visited[adj] = true;
                q[rear++] = adj;
            }
            temp = temp->next;
        }
    }
    std::cout << "\n";
}

// Helper recursive function for DFS
void dfsHelper(Graph &graph, int vertex, std::vector<bool> &visited) {
    visited[vertex] = true;
    std::cout << vertex << " ";

    Node *temp = graph.headArray[vertex];
    while (temp != nullptr) {
        int adj = temp->dest;
        if (!visited[adj]) {
            dfsHelper(graph, adj, visited);
        }
        temp = temp->next;
    }
}

// 2. Depth-First Search (DFS)
void runDFS(Graph &graph, int startVertex) {
    std::vector<bool> visited(graph.V, false);
    std::cout << "DFS: ";
    dfsHelper(graph, startVertex, visited);
    std::cout << "\n";
}

int main() {
    Graph graph(5);

    // Setup a sample graph:
    // 0 --- 1 --- 3
    // |   /
    // |  /
    // 2 --- 4
    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 2);
    graph.addEdge(1, 3);
    graph.addEdge(2, 4);

    runBFS(graph, 0);
    runDFS(graph, 0);

    return 0;
}
