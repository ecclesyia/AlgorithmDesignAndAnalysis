// Session 08: Prim's Minimum Spanning Tree (MST) in Java

public class prim_mst {
    private static final int V = 5;
    private static final int INF = 999999;

    public static int minKey(int[] key, boolean[] mstSet) {
        int min = INF;
        int minIndex = -1;
        for (int v = 0; v < V; v++) {
            if (!mstSet[v] && key[v] < min) {
                min = key[v];
                minIndex = v;
            }
        }
        return minIndex;
    }

    public static void runPrim(int[][] graph) {
        int[] parent = new int[V];
        int[] key = new int[V];
        boolean[] mstSet = new boolean[V];

        for (int i = 0; i < V; i++) {
            key[i] = INF;
            mstSet[i] = false;
        }

        key[0] = 0;
        parent[0] = -1;

        for (int count = 0; count < V - 1; count++) {
            int u = minKey(key, mstSet);
            mstSet[u] = true;

            for (int v = 0; v < V; v++) {
                if (graph[u][v] != 0 && !mstSet[v] && graph[u][v] < key[v]) {
                    parent[v] = u;
                    key[v] = graph[u][v];
                }
            }
        }

        System.out.println("Prim's MST:");
        int cost = 0;
        for (int i = 1; i < V; i++) {
            System.out.println("  " + parent[i] + " - " + i + " == " + graph[i][parent[i]]);
            cost += graph[i][parent[i]];
        }
        System.out.println("Total Cost: " + cost);
    }

    public static void main(String[] args) {
        int[][] graph = {
            {0, 2, 0, 6, 0},
            {2, 0, 3, 8, 5},
            {0, 3, 0, 0, 7},
            {6, 8, 0, 0, 9},
            {0, 5, 7, 9, 0}
        };
        runPrim(graph);
    }
}
