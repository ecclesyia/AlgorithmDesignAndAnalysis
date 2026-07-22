# Session 11: N-Queens Backtracking in Python

N = 4

def print_board(board):
    for i in range(N):
        for j in range(N):
            print(" Q " if board[i][j] else " . ", end="")
        print()
    print()

def is_safe(board, row, col):
    # Check this row on left side
    for i in range(col):
        if board[row][i]:
            return False
            
    # Check upper diagonal on left side
    i, j = row, col
    while i >= 0 and j >= 0:
        if board[i][j]:
            return False
        i -= 1
        j -= 1
        
    # Check lower diagonal on left side
    i, j = row, col
    while j >= 0 and i < N:
        if board[i][j]:
            return False
        i += 1
        j -= 1
        
    return True

def solve_n_queens_helper(board, col):
    if col >= N:
        return True
        
    for i in range(N):
        if is_safe(board, i, col):
            board[i][col] = 1
            if solve_n_queens_helper(board, col + 1):
                return True
            board[i][col] = 0  # backtrack
            
    return False

def main():
    board = [[0] * N for _ in range(N)]
    if solve_n_queens_helper(board, 0):
        print_board(board)
    else:
        print("No solution")

if __name__ == "__main__":
    main()
