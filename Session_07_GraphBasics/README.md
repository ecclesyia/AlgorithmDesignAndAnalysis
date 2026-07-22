# Session 07: Graph Representation and Basic Searches

Graphs are non-linear data structures representing networks of entities (vertices/nodes) connected by links (edges). This session covers how to represent graphs in computer memory and how to traverse them using Breadth-First Search (BFS) and Depth-First Search (DFS).

---

## Why is it Important to Learn This?

Graphs are the primary data structure used to model relational networks in computer science:
1. **Social Networks**: Users are vertices, and friendships are edges. Finding mutual friends or search suggestions relies on graph traversals.
2. **Web Crawlers**: Webpages are vertices, and hyperlinks are edges. Search engines crawl the web by running DFS or BFS over pages.
3. **GPS Routing**: Road intersections are vertices, and street segments are edges. Dijkstra's and A* pathfinding build directly on basic BFS/DFS concepts.

---

## Academic Inspiration: CS50 and MIT

This session is inspired by:
* **Harvard's CS50 (Week 5: Data Structures)**: Visualizing nodes pointing to other nodes in memory and mapping grids/mazes to trees.
* **MIT's 6.006 (Lectures 9 and 10: BFS and DFS)**: Representing graphs using adjacency lists, calculating path distances with BFS, and tracking arrival/departure times in recursive DFS to build topological sorts.

---

## Concepts Explained

### 1. Graph Representations

There are two primary ways to represent a graph in C:

#### Adjacency Matrix
A 2D array of size $V \times V$ where $matrix[i][j] = 1$ if there is an edge from vertex $i$ to vertex $j$, and $0$ otherwise.
* **Pros**: Edge lookup is $O(1)$.
* **Cons**: Consumes $O(V^2)$ memory, which is highly inefficient for sparse graphs (graphs with few edges).

```text
Adjacency Matrix (4 vertices, directed):
   0 1 2 3
0 [0, 1, 1, 0]   (Edges: 0->1, 0->2)
1 [0, 0, 0, 1]   (Edges: 1->3)
2 [0, 0, 0, 0]   (No edges)
3 [1, 0, 0, 0]   (Edges: 3->0)
```

#### Adjacency List
An array of linked lists, where each index $i$ corresponds to vertex $i$, and the linked list contains all vertices adjacent to $i$.
* **Pros**: Memory efficient, consuming $O(V + E)$ space. Very easy to find all neighbors of a vertex.
* **Cons**: Checking if an edge exists between $i$ and $j$ requires traversing the list of $i$, taking $O(V)$ worst-case.

```text
Adjacency List:
Vertex 0: [ 1 ] -> [ 2 ] -> NULL
Vertex 1: [ 3 ] -> NULL
Vertex 2: NULL
Vertex 3: [ 0 ] -> NULL
```

### 2. Graph Traversals

* **Breadth-First Search (BFS)**: Explores all vertices at the current depth level before moving to vertices at the next depth level. It uses a **Queue (FIFO)** structure and finds the shortest path in an unweighted graph.
* **Depth-First Search (DFS)**: Goes as deep as possible down a path before backtracking. It uses a **Stack (LIFO)** structure (typically through recursion stack frames) and is crucial for detecting cycles, topological sorting, and solving mazes.

---

## Code Examples

Check the files in this directory:
* [graph_representations.c](graph_representations.c) - A C program showing how to construct both an Adjacency Matrix and a dynamic Adjacency List in memory.
* [graph_search.c](graph_search.c) - A C program implementing BFS and DFS traversals on a graph, outputting the node traversal sequences.
