# Session 12: Branch and Bound

Branch and Bound (B&B) is an algorithm design paradigm for discrete and combinatorial optimization problems. It systematically explores the state space tree of all candidate solutions, using mathematical **bounds** to prune entire branches of the search space that cannot produce a solution better than the best one found so far.

This session illustrates Branch and Bound using the 0/1 Knapsack problem, comparing how it differs from Dynamic Programming and Backtracking.

---

## Why is it Important to Learn This?

Branch and Bound is the standard method for solving exact optimizations on NP-Hard problems:
1. **Integer Linear Programming**: Used in enterprise solvers (like Gurobi or CPLEX) to optimize manufacturing limits, shipping schedules, and financial portfolios under strict binary constraints.
2. **Traveling Salesperson Problem (TSP)**: Finds the absolute shortest route to visit multiple cities by calculating lower-bound distances and pruning suboptimal path options.
3. **Advanced AI Decision Trees**: Evaluates future states in chess or robotics planning by discarding bad moves immediately after bounding their outcomes.

---

## Academic Inspiration: CS50 and MIT

This session is inspired by:
* **Harvard's CS50 (Introduction to Trees and Heuristics)**: Understanding node structures, leaf weights, and using logical estimators to choose path directions.
* **MIT's 6.046 (Design and Analysis of Algorithms - Advanced Optimization)**: Formulating lower/upper bounding functions (such as using the fractional knapsack ratio relaxation as a bound for the 0/1 knapsack problem) and implementing Best-First Search using Priority Queues.

---

## Concepts Explained

### 1. Backtracking vs. Branch and Bound

* **Backtracking** traverses the state space tree using **Depth-First Search (DFS)**. It only prunes branches that violate feasibility constraints.
* **Branch and Bound** typically traverses using **Breadth-First Search (BFS)** or **Best-First Search (using a Priority Queue)**. It calculates estimated bounds to prune branches that, although feasible, are mathematically guaranteed not to beat the current best solution.

### 2. Bounding Function for 0/1 Knapsack

To prune subtrees, we calculate the **Upper Bound** of the maximum value we could get from a node's remaining capacity:
1. We take items greedily (like Fractional Knapsack).
2. If an item fits completely, we add its value.
3. If the next item doesn't fit completely, we add a fraction of its value to fill the remaining capacity.
4. This fractional total acts as a relaxation upper bound: because a fractional selection is always at least as valuable as a binary 0/1 selection, if this bound is less than our current max profit, we can safely **prune** this node and its children.

```text
Branch and Bound Node Tree:
                 [ Node 0: profit=0, weight=0, bound=220 ]
                 /                                       \
          Include Item 1                               Exclude Item 1
    [ Node 1: profit=60, bound=220 ]          [ Node 2: profit=0, bound=160 ]
             /            \                                     |
      Include Item 2     Exclude Item 2                 (If current max is 180,
[ Node 3: profit=160 ]   [ Node 4: profit=60 ]          Node 2's bound (160) < 180.
                                                        Prune entire subtree!)
```

---

## Code Examples

Check the files in this directory:
* [knapsack_branch_bound.c](knapsack_branch_bound.c) - A C program solving the 0/1 Knapsack problem using a Breadth-First search Branch and Bound strategy, demonstrating active node evaluation and bounding-based pruning.
