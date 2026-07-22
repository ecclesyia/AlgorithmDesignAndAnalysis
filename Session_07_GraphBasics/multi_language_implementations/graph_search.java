// Session 07: BFS and DFS Traversals in Java
// Uses an Adjacency List graph representation to demonstrate:
// 1. Breadth-First Search (Queue-based)
// 2. Depth-First Search (Recursive)

public class graph_search {
    static class Node {
        int dest;
        Node next;
        Node(int dest) {
            this.dest = dest;
            this.next = null;
        }
    }

    static class Graph {
        int V;
        Node[] headArray;

        Graph(int vertices) {
            this.V = vertices;
            this.headArray = new Node[vertices];
        }

        // Add undirected edge
        void addEdge(int src, int dest) {
            Node node1 = new Node(dest);
            node1.next = this.headArray[src];
            this.headArray[src] = node1;

            Node node2 = new Node(src);
            node2.next = this.headArray[dest];
            this.headArray[dest] = node2;
        }
    }

    // 1. Breadth-First Search (BFS)
    public static void runBFS(Graph graph, int startVertex) {
        boolean[] visited = new boolean[graph.V];
        int[] queue = new int[graph.V];
        int front = 0, rear = 0;

        visited[startVertex] = true;
        queue[rear++] = startVertex;

        System.out.print("BFS: ");
        while (front < rear) {
            int curr = queue[front++];
            System.out.print(curr + " ");

            Node temp = graph.headArray[curr];
            while (temp != null) {
                int adj = temp.dest;
                if (!visited[adj]) {
                    visited[adj] = true;
                    queue[rear++] = adj;
                }
                temp = temp.next;
            }
        }
        System.out.println();
    }

    // Helper recursive function for DFS
    private static void dfsHelper(Graph graph, int vertex, boolean[] visited) {
        visited[vertex] = true;
        System.out.print(vertex + " ");

        Node temp = graph.headArray[vertex];
        while (temp != null) {
            int adj = temp.dest;
            if (!visited[adj]) {
                dfsHelper(graph, adj, visited);
            }
            temp = temp.next;
        }
    }

    // 2. Depth-First Search (DFS)
    public static void runDFS(Graph graph, int startVertex) {
        boolean[] visited = new boolean[graph.V];
        System.out.print("DFS: ");
        dfsHelper(graph, startVertex, visited);
        System.out.println();
    }

    public static void main(String[] args) {
        Graph graph = new Graph(5);

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
    }
}
