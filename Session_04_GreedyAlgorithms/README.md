# Session 04: Greedy Algorithms

A Greedy algorithm solves an optimization problem by making the locally optimal choice at each stage with the hope of finding the global optimum. Unlike Dynamic Programming, a greedy algorithm never reconsiders its past choices.

---

## Why is it Important to Learn This?

Greedy algorithms are extremely efficient. While finding an exact optimal solution using brute force might take exponential time $O(2^n)$, a greedy approach often runs in linearithmic time $O(n \log n)$ or linear time $O(n)$. 

Understanding greedy design allows you to:
1. Construct highly optimized heuristic systems when absolute precision is not required.
2. Solve classic scheduling, compression (like Huffman coding), and spanning tree problems efficiently.
3. Prove mathematically whether a local optimization rule leads to a globally correct solution.

---

## Academic Inspiration: CS50 and MIT

This session is inspired by:
* **Harvard's CS50 (Week 3/5: Greedy Choice)**: Explaining currency coin change logic (always picking the largest coin denomination first) and identifying when that greedy choice fails (e.g., if coin values are arbitrary).
* **MIT's 6.046 (Greedy Algorithms Lecture)**: Defining the formal requirements of a greedy proof (greedy choice property and optimal substructure) and analyzing fractional knapsack and activity selection properties.

---

## Concepts Explained

For a problem to be solved optimally by a greedy algorithm, it must possess two properties:
1. **Greedy Choice Property**: A global optimum can be arrived at by making a local optimal (greedy) choice.
2. **Optimal Substructure**: An optimal solution to the problem contains optimal solutions to the subproblems.

### 1. Fractional Knapsack Problem

* **Problem**: You are given a set of items, each with a weight and a value. You want to maximize the total value in a knapsack of capacity $W$. You can take fractions of items.
* **Greedy Strategy**: Calculate the **value-to-weight ratio** ($v_i / w_i$) for each item. Sort items in descending order of this ratio. Take as much of the highest ratio item as possible, then move to the next.

```text
Fractional Knapsack Strategy:

Item 1: Value = 60, Weight = 10 -> Ratio = 6.0 (Sort 1st)
Item 2: Value = 100, Weight = 20 -> Ratio = 5.0 (Sort 2nd)
Item 3: Value = 120, Weight = 30 -> Ratio = 4.0 (Sort 3rd)

Knapsack Capacity = 50.
1. Take all Item 1 (Weight 10, Value 60). Remaining Capacity = 40.
2. Take all Item 2 (Weight 20, Value 100). Remaining Capacity = 20.
3. Take fraction (20/30) of Item 3 (Weight 20, Value 80). Remaining Capacity = 0.
Total Value = 60 + 100 + 80 = 240.
```

### 2. Activity Selection Problem

* **Problem**: You are given $n$ activities, each with a start time $s_i$ and a finish time $f_i$. Select the maximum number of mutually compatible activities that can be performed by a single person.
* **Greedy Strategy**: Sort the activities in ascending order of their **finish times**. Always select the next compatible activity that finishes earliest.

```text
Activity Selection Strategy:

Activity A: [1, 4]  (Finishes at 4 - Select 1st)
Activity B: [3, 5]  (Clashes with A - Skip)
Activity C: [0, 6]  (Clashes with A - Skip)
Activity D: [5, 7]  (Starts after A finishes - Select 2nd)
Activity E: [8, 9]  (Starts after D finishes - Select 3rd)

Selected: A -> D -> E (Total 3 activities)
```

---

## Code Examples

Check the files in this directory:
* [fractional_knapsack.c](fractional_knapsack.c) - A C program solving the Fractional Knapsack problem using a struct array sorted by value-to-weight ratio.
* [activity_selection.c](activity_selection.c) - A C program solving the Activity Selection scheduling problem by sorting finish times.
