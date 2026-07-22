const val N = 4

fun printBoard(board: Array<IntArray>) {
    for (i in 0 until N) {
        for (j in 0 until N) {
            if (board[i][j] == 1) {
                print(" Q ")
            } else {
                print(" . ")
            }
        }
        println()
    }
    println()
}

fun isSafe(board: Array<IntArray>, row: Int, col: Int): Boolean {
    // Check this row on left side
    for (i in 0 until col) {
        if (board[row][i] == 1) return false
    }

    // Check upper diagonal on left side
    var i = row
    var j = col
    while (i >= 0 && j >= 0) {
        if (board[i][j] == 1) return false
        i--
        j--
    }

    // Check lower diagonal on left side
    i = row
    j = col
    while (j >= 0 && i < N) {
        if (board[i][j] == 1) return false
        i++
        j--
    }

    return true
}

fun solveNQueensHelper(board: Array<IntArray>, col: Int): Boolean {
    if (col >= N) return true

    for (i in 0 until N) {
        if (isSafe(board, i, col)) {
            board[i][col] = 1

            println("Trying placement at Row $i, Col $col:")
            printBoard(board)

            if (solveNQueensHelper(board, col + 1)) {
                return true
            }

            board[i][col] = 0
            println("Backtracking: Removed Queen from Row $i, Col $col\n")
        }
    }
    return false
}

fun solveNQueens() {
    val board = Array(N) { IntArray(N) }

    if (!solveNQueensHelper(board, 0)) {
        println("Solution does not exist")
        return
    }

    println("=== Final Solution Found ===")
    printBoard(board)
}

fun main() {
    println("=== Backtracking: N-Queens Solver (N = $N) ===\n")
    solveNQueens()

    print("Press Enter to exit...")
    readLine()
}
