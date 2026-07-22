# Session 09: Shortest Path Algorithms

Finding the shortest route between locations is one of the most common computational problems. This session covers Single-Source Shortest Path (using Dijkstra's algorithm) and All-Pairs Shortest Path (using the Floyd-Warshall dynamic programming algorithm).

---

## Why is it Important to Learn This?

Shortest path algorithms power crucial logistics and communication backbones globally:
1. **Navigation Systems**: Apps like Google Maps and Apple Maps represent road networks as weighted graphs and run optimized Dijkstra/A* variations to determine driving routes.
2. **IP Packet Routing**: Internet routers use OSPF (Open Shortest Path First) protocols based on Dijkstra's algorithm to direct packets across the web with minimum latency.
3. **Game Development**: Artificial Intelligence (AI) characters navigate game worlds using graph pathfinding grids.

---

## Academic Inspiration: CS50 and MIT

This session is inspired by:
* **Harvard's CS50 (Game Design / Pathfinding)**: Explaining grids and calculating coordinates recursively to move actors in games.
* **MIT's 6.006 (Lectures 15, 16, and 17: Shortest Paths)**: Deriving edge relaxation equations ($d[v] = \min(d[v], d[u] + w(u,v))$), proving Dijkstra correctness using greedy bounds, and constructing Floyd-Warshall's cubic dynamic programming transitions.

---

## Concepts Explained

### 1. Edge Relaxation

At the core of shortest path algorithms is the concept of **relaxation**. To relax an edge from $u$ to $v$ means to test whether we can improve the shortest path to $v$ found so far by going through $u$.

```text
Relaxation Equation:
If dist[u] + weight(u, v) < dist[v]:
    dist[v] = dist[u] + weight(u, v)
```

### 2. Dijkstra's Algorithm (Single-Source)

Dijkstra's is a greedy algorithm that finds the shortest paths from a single source vertex to all other vertices in a graph with non-negative edge weights.
1. Assign to every node a tentative distance value: set it to zero for the source node, and to infinity for all other nodes.
2. Mark all nodes unvisited. Set the source node as current.
3. For the current node, consider all of its unvisited neighbors and calculate their tentative distances through the current node. Compare the newly calculated tentative distance to the current assigned value and assign the smaller one.
4. When we are done considering all of the neighbors of the current node, mark the current node as visited. A visited node will never be checked again.
5. If the destination node has been marked visited, or if the smallest tentative distance among the nodes in the unvisited set is infinity, then stop.
6. Otherwise, select the unvisited node that is marked with the smallest tentative distance, set it as the new "current node", and go back to step 3.

### 3. Floyd-Warshall Algorithm (All-Pairs)

Floyd-Warshall is a dynamic programming algorithm that finds the shortest paths between all pairs of vertices in a weighted graph (even with negative weights, as long as there are no negative weight cycles).
* Let $dp[i][j][k]$ be the shortest path from $i$ to $j$ using only vertices from the set $\{1, 2, \dots, k\}$ as intermediate nodes.
* **DP Recurrence**:
  \[dp[i][j][k] = \min(dp[i][j][k-1], dp[i][k][k-1] + dp[k][j][k-1])\]
  We can optimize this to use a 2D array in-place.

---

## Code Examples

Check the files in this directory:
* [dijkstra.c](dijkstra.c) - A C program implementing Dijkstra's single-source shortest path algorithm using an adjacency matrix.
* [floyd_warshall.c](floyd_warshall.c) - A C program implementing Floyd-Warshall's all-pairs shortest path dynamic programming algorithm.
