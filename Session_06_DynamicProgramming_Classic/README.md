# Session 06: Dynamic Programming II: Classic Problems

This session explores classic, multi-dimensional Dynamic Programming problems: Longest Common Subsequence (LCS) and the 0/1 Knapsack problem. We focus on constructing 2D state tables and backtracking through them to reconstruct optimal solution selections.

---

## Why is it Important to Learn This?

Many real-world algorithms require selecting optimal subsets or alignments from multiple data sequences:
1. **Bioinformatics**: DNA sequence alignment (e.g., matching gene patterns) uses Longest Common Subsequence logic to determine evolutionary similarity.
2. **Version Control Tools**: `git diff` uses LCS variants to detect which lines were inserted, modified, or deleted.
3. **Resource Allocation**: The 0/1 Knapsack problem models shipping container packing, financial portfolio allocation, and CPU task scheduling, where items cannot be split (either you take it, 1, or leave it, 0).

---

## Academic Inspiration: CS50 and MIT

This session is inspired by:
* **Harvard's CS50 (Applications of DP)**: Understanding how character matching maps to grid grids, and how search paths find optimal intersections.
* **MIT's 6.006 (Lecture 21: LCS and Knapsack)**: Deriving state transition formulas, proving optimal substructure bounds, and writing C code to trace through 2D tables from bottom-right back to top-left.

---

## Concepts Explained

### 1. Longest Common Subsequence (LCS)

* **Problem**: Given two strings $S1$ and $S2$, find the length of the longest subsequence present in both. Unlike substrings, subsequences do not need to be contiguous.
* **DP Recurrence**:
  Let $dp[i][j]$ be the LCS of $S1[0..i-1]$ and $S2[0..j-1]$:
  - If $S1[i-1] == S2[j-1]$, then $dp[i][j] = dp[i-1][j-1] + 1$
  - If $S1[i-1] \neq S2[j-1]$, then $dp[i][j] = \max(dp[i-1][j], dp[i][j-1])$

```text
LCS 2D Table for S1 = "STONE", S2 = "LONEST":

    -  L  O  N  E  S  T
 - [0, 0, 0, 0, 0, 0, 0]
 S [0, 0, 0, 0, 0, 1, 1]
 T [0, 0, 0, 0, 0, 1, 2]
 O [0, 0, 1, 1, 1, 1, 2]
 N [0, 0, 1, 2, 2, 2, 2]
 E [0, 0, 1, 2, 3, 3, 3]

LCS Length: 3 ("ONE")
Backtracking starts at dp[5][6] and follows arrows diagonally up-left when characters match.
```

### 2. 0/1 Knapsack Problem

* **Problem**: Pack items into a knapsack of capacity $W$. Each item has value $val[i]$ and weight $wt[i]$. You must choose either to include the item or exclude it (no fractions).
* **DP Recurrence**:
  Let $dp[i][w]$ be the max value of first $i$ items with capacity limit $w$:
  - If $wt[i-1] > w$, then $dp[i][w] = dp[i-1][w]$ (Cannot fit)
  - Else, $dp[i][w] = \max(dp[i-1][w], val[i-1] + dp[i-1][w - wt[i-1]])$

---

## Code Examples

Check the files in this directory:
* [longest_common_subsequence.c](longest_common_subsequence.c) - A C program building a 2D table to find the LCS of two strings and backtracking to print the actual character string.
* [knapsack_01.c](knapsack_01.c) - A C program implementing the 0/1 Knapsack problem, showing the DP grid, and backtracking to identify the exact items packed.
