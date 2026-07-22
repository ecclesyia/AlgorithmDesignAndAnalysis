# Session 02: Recurrent Algorithms and Recurrences

Recursion is a fundamental programming technique where a function calls itself to solve a smaller subproblem. In algorithm design, recurrence relations are the mathematical equations used to define and analyze the time complexity of these recursive algorithms.

---

## Why is it Important to Learn This?

Many of the most efficient algorithms (like Merge Sort, Quick Sort, and Fast Fourier Transform) are recursive. However, analyzing their complexity is not as simple as counting nested loops. If you do not understand recurrences:
1. You may write recursion that triggers a stack overflow (running out of system call stack memory).
2. You cannot calculate the performance of divide-and-conquer systems.
3. You will struggle to optimize algorithms that rely on state branch pruning.

---

## Academic Inspiration: CS50 and MIT

This session is inspired by:
* **Harvard's CS50 (Week 3: Call Stack & Recursion)**: Visually demonstrating how stack frames are pushed onto the call stack and popped off upon returning, and how infinite recursion exhausts stack memory.
* **MIT's 6.006 / 6.046 (Recurrences and Master Theorem)**: Analyzing recurrence equations mathematically using the Master Theorem and solving tree structures recursively.

---

## Concepts Explained

### 1. The Call Stack and Recursion Memory

Every recursive call creates a new **Stack Frame** in the system memory. This frame stores:
1. Local variables of that specific function invocation.
2. Parameter arguments.
3. The return address (where to resume in the parent function).

```text
Visual Representation of the Call Stack during recursive fibonacci(3):

[ Call 4 ] fibonacci(1) -> returns 1  (Top of Stack - Active)
[ Call 3 ] fibonacci(2) -> waits for fibonacci(1)
[ Call 2 ] fibonacci(3) -> waits for fibonacci(2)
[ Call 1 ] main()       -> waits for fibonacci(3)
```

If your recursion does not have a valid **Base Case** (the terminating condition), it will call itself infinitely, leading to a **Stack Overflow**.

### 2. Recurrence Relations

A recurrence relation defines the time complexity of an algorithm of size $n$ in terms of its performance on smaller inputs. For example, the recurrence for Merge Sort is:

\[T(n) = 2T(n/2) + O(n)\]

This states: "To sort an array of size $n$, we recursively sort 2 sub-arrays of size $n/2$, and then spend $O(n)$ time merging the results."

### 3. The Master Theorem

For recurrences of the form:

\[T(n) = aT(n/b) + f(n)\]

Where:
* $a \ge 1$ is the number of recursive subproblems.
* $b > 1$ is the factor by which the input size is divided.
* $f(n)$ is the cost of dividing the work and combining the results.

We compare $f(n)$ with $n^{\log_b a}$:

* **Case 1**: If $f(n) = O(n^{\log_b a - \epsilon})$ for some $\epsilon > 0$, then $T(n) = \Theta(n^{\log_b a})$. (Subproblems dominate).
* **Case 2**: If $f(n) = \Theta(n^{\log_b a})$, then $T(n) = \Theta(n^{\log_b a} \log n)$. (Work is balanced).
* **Case 3**: If $f(n) = \Omega(n^{\log_b a + \epsilon})$ for some $\epsilon > 0$, and if $a f(n/b) \le c f(n)$ for some $c < 1$, then $T(n) = \Theta(f(n))$. (Divide/combine step dominates).

---

## Code Examples

Check the files in this directory:
* [recurrence_analysis.c](recurrence_analysis.c) - A compilable C program that demonstrates recursive execution flow, tracks recursion depth, and measures call stack utilization to prevent stack overflows.
