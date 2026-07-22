# Session 03: Divide and Conquer

Divide and Conquer is an algorithmic design paradigm that solves a problem by breaking it into smaller subproblems, solving the subproblems recursively, and then combining their solutions to solve the original problem.

---

## Why is it Important to Learn This?

Divide and Conquer is the secret behind changing quadratic time complexities $O(n^2)$ into linearithmic time complexities $O(n \log n)$. For example:
1. Standard sorting algorithms like Bubble Sort check every element against every other, taking $O(n^2)$ time. Merge Sort divides the array and achieves $O(n \log n)$ time, which is millions of times faster for large arrays.
2. In database indexing and memory lookup, scanning records linearly takes $O(n)$ time. Dividing the search space in half (Binary Search) achieves $O(\log n)$ lookup, which is almost instantaneous even for billions of records.

---

## Academic Inspiration: CS50 and MIT

This session is inspired by:
* **Harvard's CS50 (Week 3: Sorting and Searching)**: Utilizing visual sorting slides (Merge Sort, Bubble Sort) to compare theoretical growth rates and highlighting the "split-in-half" search boundaries of Binary Search.
* **MIT's 6.006 (Lecture 3 and 4: Sorting and Divide & Conquer)**: Analyzing recursion tree math, calculating partition pivots in Quick Sort, and handling temporary array allocations in Merge Sort.

---

## Concepts Explained

The Divide and Conquer model consists of three steps at each level of recursion:
1. **Divide**: Split the problem into a number of subproblems that are smaller instances of the same problem.
2. **Conquer**: Solve the subproblems recursively. If they are small enough (base case), solve them directly.
3. **Combine**: Merge the subproblem solutions into the solution for the original problem.

### 1. Merge Sort

* **Divide**: Split the $n$-element array into two halves of size $n/2$.
* **Conquer**: Sort the two halves recursively using Merge Sort.
* **Combine**: Merge the two sorted halves into a single sorted array.

```text
Merge Sort Visual Split and Merge:

      [38, 27, 43, 3]          <- Divide
      /            \
  [38, 27]       [43, 3]       <- Divide
   /    \         /    \
 [38]   [27]    [43]   [3]     <- Base cases (size 1)
   \    /         \    /
  [27, 38]       [3, 43]       <- Combine (Merge)
      \            /
      [3, 27, 38, 43]          <- Combine (Merge)
```

### 2. Quick Sort

* **Divide**: Partition the array into two sub-arrays around a **pivot** element $p$. All elements less than $p$ go to the left side, and all elements greater than $p$ go to the right side.
* **Conquer**: Recursively sort the left and right partitions.
* **Combine**: No combine step is needed since partitioning sorts the elements in-place.

```text
Quick Sort Partitioning (Pivot = 3):

Array: [5, 2, 1, 6, 3]  -> Select 3 as pivot
Partition Step:
  - Elements < 3: [2, 1]
  - Pivot: [3]
  - Elements > 3: [5, 6]
Result: [2, 1, 3, 5, 6] -> Recursively sort left [2, 1] and right [5, 6]
```

---

## Code Examples

Check the files in this directory:
* [divide_and_conquer.c](divide_and_conquer.c) - A compilable C file implementing Binary Search (recursive), Merge Sort, and Quick Sort. The code prints array states after partition and merge operations to visualize the division of labor.
