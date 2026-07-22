# Session 01: Algorithm Analysis and Asymptotic Notation

This session introduces the fundamentals of analyzing program execution efficiency. Rather than counting seconds (which change based on hardware, operating system, and compiler), we analyze algorithms by counting operational growth relative to input size.

---

## Why is it Important to Learn This?

As software engineers, we must write code that scales. An algorithm that runs instantly for 100 items might take hours, days, or even centuries if the input size increases to 1,000,000. 

By analyzing algorithms before writing them, you can:
1. Identify performance bottlenecks before deploying code.
2. Select the optimal data structure and algorithm for a given input scale.
3. Understand the theoretical limits of computational speed for specific problems.

---

## Academic Inspiration: CS50 and MIT

This session is inspired by:
* **Harvard's CS50 (Week 3: Algorithms)**: Emphasizing the intuitive comparison of search algorithms and sorting boundaries, illustrating how constant factors are set aside for asymptotic growth.
* **MIT's 6.006 (Lecture 1: Algorithmic Complexity)**: Defining the formal mathematical bounds (Big-O, Big-Omega, Big-Theta) and checking loop bounds strictly.

---

## Concepts Explained

### 1. Asymptotic Notation

We use three primary notations to bound the running time of an algorithm:

```text
Notation     Mathematical Bound    Real-World Interpretation
O(g(n))      Upper Bound           Worst-case performance limit
Omega(g(n))  Lower Bound           Best-case performance limit
Theta(g(n))  Tight Bound           Average/exact performance behavior
```

#### Visual Representation of Growth Rates
As input size (n) approaches infinity, the growth rates diverge significantly:

```text
Complexity | Name         | Growth Rate Comparison for n = 1000
-----------|--------------|--------------------------------------
O(1)       | Constant     | 1 operation
O(log n)   | Logarithmic  | ~10 operations
O(n)       | Linear       | 1,000 operations
O(n log n) | Linearithmic | ~10,000 operations
O(n^2)     | Quadratic    | 1,000,000 operations
O(2^n)     | Exponential  | 1.07 * 10^301 operations (Uncomputable!)
```

### 2. Identifying Complexities in C

* **Constant Time O(1)**: Single instruction execution with no dependency on input size.
  ```c
  int val = array[5]; // Instant array access
  ```
* **Logarithmic Time O(log n)**: The problem size is divided by a constant factor in each step (e.g., binary search, binary heap operations).
  ```c
  while (n > 1) {
      n /= 2;
  }
  ```
* **Linear Time O(n)**: Iterating through an array once.
  ```c
  for (int i = 0; i < n; i++) {
      printf("%d\n", array[i]);
  }
  ```
* **Linearithmic Time O(n log n)**: Divide-and-conquer sorting algorithms (Merge Sort, Quick Sort, Heap Sort).
* **Quadratic Time O(n^2)**: Nested iterations over the input (e.g., Bubble Sort, Selection Sort, checking every pair of elements).
  ```c
  for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
          printf("%d\n", matrix[i][j]);
      }
  }
  ```

---

## Code Examples

Check the files in this directory:
* [complexity_examples.c](complexity_examples.c) - A compilable C file containing isolated functions representing each major time complexity class, showing how loop counters and input divisions map to mathematical growth rates.
