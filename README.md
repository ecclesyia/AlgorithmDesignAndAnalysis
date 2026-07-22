# Binus Algorithm Design and Analysis Course Companion (Session-Based)

Welcome to the Algorithm Design and Analysis course companion repository. This repository follows a structured, session-based curriculum designed to train students to study algorithms and their underlying data structures using the C programming language.

Unlike simple programming courses, this companion focuses on the theoretical logic, mathematical proofs, and low-level memory implementations that define efficient software engineering. It is designed to bridge the gap between writing code that "works" and writing code that is "optimal."

---

## Why Learn Algorithm Design and Analysis?

Writing a program that executes successfully is only the first step. In real-world software systems handling millions of requests or gigabytes of data, code efficiency is the difference between a system that runs in milliseconds and one that crashes due to memory exhaustion or timeouts.

By studying Algorithm Design and Analysis, you will learn to:
1. **Predict Performance**: Measure and mathematically prove the efficiency of your code using asymptotic notation (Big-O) before running it.
2. **Solve Complex Challenges**: Master fundamental paradigms (Divide and Conquer, Greedy Algorithms, Dynamic Programming, Backtracking, Branch and Bound) that allow you to solve computationally hard problems.
3. **Optimize Memory Usage**: Gain control over stack vs. heap allocation, pointer arithmetic, and cache efficiency in standard C.
4. **Pass Technical Interviews**: Build a deep mental model of algorithms and data structures commonly tested in top-tier tech companies.

---

## Academic Inspiration: CS50 and MIT

This course is heavily inspired by and references academic standards from two of the world's leading computer science programs:
* **Harvard University's CS50 (Introduction to Computer Science)**: Borrowing its pedagogical style of starting with clear, visual explanations, low-level memory safety, and structural pointer diagrams.
* **MIT's 6.006 (Introduction to Algorithms)** and **6.046 (Design and Analysis of Algorithms)**: Incorporating rigorous complexity analysis, dynamic programming table states, and formal graph representations.

---

## Development Environment Setup Guides

Before compiling and running the C code implementations, ensure you configure your environment:
* [Dev-C++ Installation and Setup Guide](dev_c_setup.md) - Learn how to set up the default compiler, enable the C11 standard (`-std=c11`), and troubleshoot compiler errors.
* [VS Code C Setup Guide](vscode_c_setup.md) - Learn how to set up MSYS2 GCC, configure the compiler path, and set up build tasks in VS Code.

---

## Session-Based Course Modules

### Session 01: Algorithm Analysis and Asymptotic Notation
* **Concepts**: Time and space complexity, growth of functions, Big-O, Big-Omega, and Big-Theta notations.
* **Why it matters**: Allows you to compare code efficiency without depending on hardware.
* **Academic Context**: Inspired by MIT 6.006 Lecture 1 on algorithmic complexity.
* [Session 01 Module](Session_01_AlgorithmAnalysis/README.md)

### Session 02: Recurrent Algorithms and Recurrences
* **Concepts**: Recursive function call stacks, recursion tree method, substitution method, and the Master Theorem.
* **Why it matters**: Essential for understanding how modern divide-and-conquer systems allocate stack frames.
* **Academic Context**: Inspired by MIT 6.046 Recurrence Lecture.
* [Session 02 Module](Session_02_Recurrences/README.md)

### Session 03: Divide and Conquer
* **Concepts**: Divide, conquer, and combine paradigm. Binary Search, Merge Sort, and Quick Sort.
* **Why it matters**: The foundation of parallel computing and efficient file sorting.
* **Academic Context**: Inspired by CS50 sorting/searching animations and MIT 6.006 sorting lectures.
* [Session 03 Module](Session_03_DivideAndConquer/README.md)

### Session 04: Greedy Algorithms
* **Concepts**: Greedy choice property, optimal substructure, fractional knapsack, and activity selection.
* **Why it matters**: Solves complex optimization problems quickly by choosing the local best.
* **Academic Context**: Inspired by MIT 6.046 Greedy algorithms.
* [Session 04 Module](Session_04_GreedyAlgorithms/README.md)

### Session 05: Dynamic Programming I: Memoization and Tabulation
* **Concepts**: Overlapping subproblems, memoization (top-down) vs. tabulation (bottom-up).
* **Why it matters**: Turns exponential-time recursive solutions into linear-time lookup solutions.
* **Academic Context**: Inspired by MIT 6.006 Dynamic Programming lectures.
* [Session 05 Module](Session_05_DynamicProgramming_Basics/README.md)

### Session 06: Dynamic Programming II: Classic Problems
* **Concepts**: Longest Common Subsequence (LCS), 0/1 Knapsack, and path reconstruction using 2D state tables.
* **Why it matters**: Crucial for string alignment (DNA analysis, diff tools) and resource allocation.
* **Academic Context**: Inspired by MIT 6.006 advanced DP examples.
* [Session 06 Module](Session_06_DynamicProgramming_Classic/README.md)

### Session 07: Graph Representation and Basic Searches
* **Concepts**: Vertices, edges, adjacency matrices, adjacency lists, Breadth-First Search (BFS), and Depth-First Search (DFS).
* **Why it matters**: The bedrock of routing algorithms, social networks, and web crawlers.
* **Academic Context**: Inspired by CS50's graph visualization and MIT 6.006 Graph lectures.
* [Session 07 Module](Session_07_GraphBasics/README.md)

### Session 08: Minimum Spanning Trees (MST)
* **Concepts**: Kruskal's algorithm (using Disjoint Set Union) and Prim's algorithm (using Priority Queues).
* **Why it matters**: Optimizes cable connections, network layouts, and transportation grids.
* **Academic Context**: Inspired by MIT 6.046 Greedy/MST lectures.
* [Session 08 Module](Session_08_MST/README.md)

### Session 09: Shortest Path Algorithms
* **Concepts**: Dijkstra's algorithm, Bellman-Ford algorithm, and Floyd-Warshall algorithm.
* **Why it matters**: Powers GPS navigation systems and internet packet routing.
* **Academic Context**: Inspired by MIT 6.006 Shortest Paths (Dijkstra/Bellman-Ford).
* [Session 09 Module](Session_09_ShortestPaths/README.md)

### Session 10: String Matching Algorithms
* **Concepts**: Brute force search, Rabin-Karp (rolling hashes), and Knuth-Morris-Pratt (KMP) (Prefix function/LPS table).
* **Why it matters**: Underpins search engines, text editors, and anti-plagiarism checks.
* **Academic Context**: Inspired by MIT 6.006 String Matching lectures.
* [Session 10 Module](Session_10_StringMatching/README.md)

### Session 11: Backtracking and State Space Search
* **Concepts**: State space trees, backtracking recursive algorithms, and depth-first pruning.
* **Why it matters**: Powers solvers for puzzles, scheduling problems, and constraint satisfaction.
* **Academic Context**: Inspired by CS50 recursion depth examples.
* [Session 11 Module](Session_11_Backtracking/README.md)

### Session 12: Branch and Bound
* **Concepts**: Lower/upper bound functions, best-first search, and active state space pruning via priority queues.
* **Why it matters**: Solves exact integer linear programming and NP-hard optimization problems.
* **Academic Context**: Inspired by MIT 6.046 advanced discrete algorithms.
* [Session 12 Module](Session_12_BranchAndBound/README.md)
