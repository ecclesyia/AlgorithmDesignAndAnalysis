# Session 11: Backtracking and State Space Search

Backtracking is an algorithmic paradigm that searches depth-first for a solution to a decision problem by incrementally building candidates, and abandoning ("backtracking" from) a candidate as soon as it determines that the candidate cannot lead to a valid solution.

This session illustrates the backtracking process using the classic N-Queens puzzle, where queens must be positioned on an $N \times N$ chessboard such that no two queens attack each other.

---

## Why is it Important to Learn This?

Backtracking is the primary technique used to solve constraint satisfaction problems (CSPs):
1. **Puzzles and Solvers**: Games like Sudoku, Crosswords, Map Coloring, and maze solving are solved by exploring paths and undoing invalid decisions.
2. **Compiler Parser Engines**: Compilers parsing syntax structures attempt to match grammar rules by descending down syntactic trees and backtracking if a syntax branch fails.
3. **Database Query Planners**: SQL query optimizer engines evaluate join options by building recursive join trees and pruning suboptimal combinations.

---

## Academic Inspiration: CS50 and MIT

This session is inspired by:
* **Harvard's CS50 (Recursion and Grid Search)**: Solving mazes recursively, showing how base cases return success/failure, and how cells are marked/unmarked.
* **MIT's 6.006 (Recursion and Exhaustive Search)**: Representing state spaces as trees, analyzing branching factors, and defining rules to prune search sub-branches early (saving exponential search overhead).

---

## Concepts Explained

### 1. State Space Trees

A backtracking algorithm can be thought of as traversing a **State Space Tree**, where:
* The root represents the initial state before any decisions are made.
* Each node represents a partial candidate solution.
* Edges represent choices.
* Leaves represent completed candidate solutions (either valid solutions or dead ends).

```text
State Space Search Tree (Subset sum example for {1, 2} target 3):

                [ Root ]
               /        \
          Add 1        Skip 1
         /     \       /     \
      [1]      []     [2]    []
     /   \     / \    / \    / \
   [1,2] [1] [2] []  [2] []  []  []
  (Sum=3)
  *Success!
```

### 2. The Backtracking Blueprint

The general recursive structure for backtracking in C:

```c
bool solve(State state) {
    if (isGoal(state)) {
        return true; // Solution found!
    }
    
    for (all possible choices) {
        if (isValid(choice, state)) {
            makeDecision(choice, state); // Step Forward
            
            if (solve(state)) {
                return true; // Propagate success
            }
            
            undoDecision(choice, state); // Step Backward (Backtrack)
        }
    }
    return false; // Triggers backtracking in parent call
}
```

---

## Code Examples

Check the files in this directory:
* [n_queens.c](n_queens.c) - A C program solving the N-Queens problem recursively, displaying every board configuration that is checked to illustrate the trial, error, and backtracking sequence.
