# Session 05: Dynamic Programming I: Memoization and Tabulation

Dynamic Programming (DP) is a method for solving complex problems by breaking them down into simpler subproblems. It is applicable to problems exhibiting the properties of overlapping subproblems and optimal substructure.

---

## Why is it Important to Learn This?

Dynamic Programming is one of the most powerful optimization paradigms. It converts algorithms that would take exponential time $O(2^n)$ (and hence would hang for even modest inputs of size $n=50$) into algorithms that run in linear time $O(n)$ or polynomial time $O(n^2)$. 

By mastering Dynamic Programming, you will learn to:
1. Avoid redundant computations by saving computed states in memory (trading space for time).
2. Recognize how overlapping branches in a recursion tree can be flattened.
3. Solve optimization problems in networking, finance, and logistics where options depend on previous sub-state choices.

---

## Academic Inspiration: CS50 and MIT

This session is inspired by:
* **Harvard's CS50 (Recursion & Performance)**: Discussing the massive waste in recursive Fibonacci calculations where `fib(3)` is computed multiple times, introducing the concept of caching values.
* **MIT's 6.006 (Lectures 19 and 20: Dynamic Programming)**: Introducing the five-step DP structure: (1) Define subproblems, (2) Guess part of the solution, (3) Relate subproblem solutions, (4) Recurse & Memoize OR Tabulate, (5) Solve the original problem.

---

## Concepts Explained

### 1. Key Properties of Dynamic Programming

1. **Overlapping Subproblems**: The recursive search tree contains the same subproblems repeatedly.
2. **Optimal Substructure**: The optimal solution to the problem can be constructed from optimal solutions to its subproblems.

### 2. Top-Down (Memoization) vs. Bottom-Up (Tabulation)

```text
Feature             Memoization (Top-Down)               Tabulation (Bottom-Up)
----------------------------------------------------------------------------------
Approach            Recursive, starts at n and goes down  Iterative, starts at 0 and builds up
State Storage       Only computes states as needed        Computes all states in table sequence
Overhead            Call stack recursion overhead         No call stack overhead (faster execution)
Intuition           Easy to write from recursion logic    Requires defining the table filling order
```

#### Visualizing Fibonacci Recursion Tree waste (n=4):
```text
                  fib(4)
                 /      \
             fib(3)      fib(2)
             /    \       /    \
         fib(2)  fib(1) fib(1) fib(0)
         /    \
     fib(1)  fib(0)

Notice that fib(2) is calculated twice, and fib(1) is calculated three times.
With Memoization, once fib(2) is calculated, its value is saved in an array and reused.
```

---

## Code Examples

Check the files in this directory:
* [fibonacci_dp.c](fibonacci_dp.c) - A C program comparing standard recursion, memoization, and tabulation for calculating Fibonacci numbers, measuring actual execution times.
* [coin_change.c](coin_change.c) - A C program solving the Coin Change problem (finding the minimum number of coins to make a given change amount) using Bottom-Up Tabulation.
