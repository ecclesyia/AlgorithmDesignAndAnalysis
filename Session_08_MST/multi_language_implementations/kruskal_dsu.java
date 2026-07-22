// Session 08: Kruskal's Algorithm with Disjoint Set Union in Java

import java.util.Arrays;
import java.util.Comparator;

public class kruskal_dsu {
    static class Edge {
        int src, dest, weight;
        Edge(int src, int dest, int weight) {
            this.src = src;
            this.dest = dest;
            this.weight = weight;
        }
    }

    static class Graph {
        int V, E;
        Edge[] edges;
        Graph(int V, int E) {
            this.V = V;
            this.E = E;
            this.edges = new Edge[E];
        }
    }

    static class Subset {
        int parent, rank;
    }

    public static int find(Subset[] subsets, int i) {
        if (subsets[i].parent != i) {
            subsets[i].parent = find(subsets, subsets[i].parent);
        }
        return subsets[i].parent;
    }

    public static void union(Subset[] subsets, int x, int y) {
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

    public static void runKruskal(Graph graph) {
        int V = graph.V;
        Edge[] result = new Edge[V - 1];
        int e = 0;
        int i = 0;

        Arrays.sort(graph.edges, new Comparator<Edge>() {
            @Override
            public int compare(Edge a, Edge b) {
                return a.weight - b.weight;
            }
        });

        Subset[] subsets = new Subset[V];
        for (int v = 0; v < V; v++) {
            subsets[v] = new Subset();
            subsets[v].parent = v;
            subsets[v].rank = 0;
        }

        while (e < V - 1 && i < graph.E) {
            Edge nextEdge = graph.edges[i++];
            int x = find(subsets, nextEdge.src);
            int y = find(subsets, nextEdge.dest);
            if (x != y) {
                result[e++] = nextEdge;
                union(subsets, x, y);
            }
        }

        System.out.println("Kruskal MST Edges:");
        int cost = 0;
        for (i = 0; i < e; i++) {
            System.out.println("  " + result[i].src + " - " + result[i].dest + " == " + result[i].weight);
            cost += result[i].weight;
        }
        System.out.println("Total Cost: " + cost);
    }

    public static void main(String[] args) {
        Graph graph = new Graph(4, 5);
        graph.edges[0] = new Edge(0, 1, 10);
        graph.edges[1] = new Edge(0, 2, 6);
        graph.edges[2] = new Edge(0, 3, 5);
        graph.edges[3] = new Edge(1, 3, 15);
        graph.edges[4] = new Edge(2, 3, 4);

        runKruskal(graph);
    }
}
