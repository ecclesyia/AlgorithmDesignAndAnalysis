# Session 08: Minimum Spanning Trees

A Minimum Spanning Tree (MST) is a subset of the edges of a connected, edge-weighted undirected graph that connects all the vertices together, without any cycles, and with the minimum possible total edge weight.

This session covers two classic greedy algorithms to construct an MST: Kruskal's algorithm (which utilizes a Disjoint Set Union data structure) and Prim's algorithm (which builds nodes outward from a single point).

---

## Why is it Important to Learn This?

Minimum Spanning Trees are fundamental to designing networks efficiently:
1. **Infrastructure Layout**: Designing power grids, telecommunication lines, water pipe networks, and road grids to connect all nodes with minimal cost.
2. **Cluster Analysis**: Used in unsupervised machine learning (e.g., Single-Linkage Hierarchical Clustering) to group similar data nodes.
3. **Approximation Algorithms**: Solving NP-hard routing problems (such as the Traveling Salesperson Problem) within a guaranteed factor of the optimal path.

---

## Academic Inspiration: CS50 and MIT

This session is inspired by:
* **Harvard's CS50 (Data Structures and Graphs)**: Studying disjoint groupings and using arrays to represent connections in union sets.
* **MIT's 6.046 (Design and Analysis of Algorithms - MST Lecture)**: Proving the **Cut Property** (which guarantees that the minimum weight edge crossing a cut belongs to the MST) and evaluating Kruskal's complexity with Disjoint Sets.

---

## Concepts Explained

### 1. Kruskal's Algorithm

Kruskal's is an edge-based greedy algorithm:
1. Sort all the edges in non-decreasing order of their weight.
2. Pick the smallest edge. Check if it forms a cycle with the spanning tree formed so far.
3. If it does not form a cycle, include this edge. Else, discard it.
4. Repeat until there are $V - 1$ edges in the spanning tree.

To check for cycles efficiently in $O(\log V)$ time, we use a **Disjoint Set Union (DSU)** data structure. DSU maintains a set of elements partitioned into non-overlapping subsets, optimizing:
- **Find**: Determine which subset a element belongs to. Optimized with **Path Compression** (pointing nodes directly to root).
- **Union**: Merge two subsets. Optimized by **Union by Rank** (attaching the shorter tree under the taller tree).

```text
Kruskal Edge Selection:
Edges sorted by weight:
1. (0, 1) w=1 -> Add to MST
2. (1, 2) w=2 -> Add to MST
3. (0, 2) w=3 -> Forms cycle with (0-1) and (1-2) -> Skip!
4. (2, 3) w=4 -> Add to MST
```

### 2. Prim's Algorithm

Prim's is a vertex-based greedy algorithm:
1. Initialize the MST with a single vertex, chosen arbitrarily.
2. Grow the MST by one vertex at a time: find the minimum-weight edge connecting a vertex in the MST to a vertex outside the MST.
3. Add the edge and the new vertex to the MST.
4. Repeat until all vertices are in the MST.

---

## Code Examples

Check the files in this directory:
* [kruskal_dsu.c](kruskal_dsu.c) - A C program implementing Kruskal's MST algorithm using a Disjoint Set Union (DSU) structure.
* [prim_mst.c](prim_mst.c) - A C program implementing Prim's MST algorithm using an adjacency matrix representation.
