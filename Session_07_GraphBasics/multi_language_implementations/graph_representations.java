// Session 07: Graph Representations in Java
// Shows how to represent a graph using:
// 1. Adjacency Matrix
// 2. Adjacency List

import java.util.Arrays;

public class graph_representations {
    private static final int V = 4; // Number of vertices

    // 1. Adjacency Matrix Representation
    public static void createAdjacencyMatrix(int[][] adjMatrix) {
        for (int i = 0; i < V; i++) {
            Arrays.fill(adjMatrix[i], 0);
        }

        // Add edges
        adjMatrix[0][1] = 1;
        adjMatrix[0][2] = 1;
        adjMatrix[1][3] = 1;
        adjMatrix[3][0] = 1;
    }

    public static void printAdjacencyMatrix(int[][] adjMatrix) {
        System.out.println("Adjacency Matrix:");
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                System.out.print(adjMatrix[i][j] + " ");
            }
            System.out.println();
        }
        System.out.println();
    }

    // 2. Adjacency List Representation
    static class AdjListNode {
        int dest;
        AdjListNode next;

        AdjListNode(int dest) {
            this.dest = dest;
            this.next = null;
        }
    }

    static class AdjList {
        AdjListNode head;
    }

    static class Graph {
        int numVertices;
        AdjList[] array;

        Graph(int numVertices) {
            this.numVertices = numVertices;
            this.array = new AdjList[numVertices];
            for (int i = 0; i < numVertices; i++) {
                this.array[i] = new AdjList();
            }
        }

        // Add edge to graph (Directed)
        void addEdge(int src, int dest) {
            AdjListNode newNode = new AdjListNode(dest);
            
            // Insert at head of the list for src
            newNode.next = this.array[src].head;
            this.array[src].head = newNode;
        }
    }

    public static void printGraphList(Graph graph) {
        System.out.println("Adjacency List:");
        for (int v = 0; v < graph.numVertices; v++) {
            AdjListNode curr = graph.array[v].head;
            System.out.print("  Vertex " + v + ": ");
            while (curr != null) {
                System.out.print("-> " + curr.dest + " ");
                curr = curr.next;
            }
            System.out.println("-> NULL");
        }
        System.out.println();
    }

    public static void main(String[] args) {
        // Adjacency Matrix
        int[][] adjMatrix = new int[V][V];
        createAdjacencyMatrix(adjMatrix);
        printAdjacencyMatrix(adjMatrix);

        // Adjacency List
        Graph graph = new Graph(V);
        graph.addEdge(0, 1);
        graph.addEdge(0, 2);
        graph.addEdge(1, 3);
        graph.addEdge(3, 0);
        printGraphList(graph);
    }
}
