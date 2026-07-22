import Foundation

let N = 4

func printBoard(_ board: [[Int]]) {
    for i in 0..<N {
        for j in 0..<N {
            if board[i][j] == 1 {
                print(" Q ", terminator: "")
            } else {
                print(" . ", terminator: "")
            }
        }
        print()
    }
    print()
}

func isSafe(_ board: [[Int]], _ row: Int, _ col: Int) -> Bool {
    // Check this row on left side
    for i in 0..<col {
        if board[row][i] == 1 { return false }
    }
    
    // Check upper diagonal on left side
    var i = row
    var j = col
    while i >= 0 && j >= 0 {
        if board[i][j] == 1 { return false }
        i -= 1
        j -= 1
    }
    
    // Check lower diagonal on left side
    i = row
    j = col
    while j >= 0 && i < N {
        if board[i][j] == 1 { return false }
        i += 1
        j -= 1
    }
    
    return true
}

func solveNQueensHelper(_ board: inout [[Int]], _ col: Int) -> Bool {
    if col >= N { return true }
    
    for i in 0..<N {
        if isSafe(board, i, col) {
            board[i][col] = 1
            
            print("Trying placement at Row \(i), Col \(col):")
            printBoard(board)
            
            if solveNQueensHelper(&board, col + 1) {
                return true
            }
            
            board[i][col] = 0
            print("Backtracking: Removed Queen from Row \(i), Col \(col)\n")
        }
    }
    return false
}

func solveNQueens() {
    var board = Array(repeating: Array(repeating: 0, count: N), count: N)
    
    if !solveNQueensHelper(&board, 0) {
        print("Solution does not exist")
        return
    }
    
    print("=== Final Solution Found ===")
    printBoard(board)
}

func main() {
    print("=== Backtracking: N-Queens Solver (N = \(N)) ===\n")
    solveNQueens()
    
    print("Press Enter to exit...")
    _ = readLine()
}

main()
