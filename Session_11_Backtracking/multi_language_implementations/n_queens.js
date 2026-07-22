const readline = require('readline');

const N = 4;

function printBoard(board) {
    for (let i = 0; i < N; i++) {
        let row = "";
        for (let j = 0; j < N; j++) {
            row += board[i][j] === 1 ? " Q " : " . ";
        }
        console.log(row);
    }
    console.log();
}

function isSafe(board, row, col) {
    // Check this row on left side
    for (let i = 0; i < col; i++) {
        if (board[row][i] === 1) return false;
    }

    // Check upper diagonal on left side
    for (let i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] === 1) return false;
    }

    // Check lower diagonal on left side
    for (let i = row, j = col; j >= 0 && i < N; i++, j--) {
        if (board[i][j] === 1) return false;
    }

    return true;
}

function solveNQueensHelper(board, col) {
    if (col >= N) return true;

    for (let i = 0; i < N; i++) {
        if (isSafe(board, i, col)) {
            board[i][col] = 1;

            console.log(`Trying placement at Row ${i}, Col ${col}:`);
            printBoard(board);

            if (solveNQueensHelper(board, col + 1)) {
                return true;
            }

            board[i][col] = 0;
            console.log(`Backtracking: Removed Queen from Row ${i}, Col ${col}\n`);
        }
    }
    return false;
}

function solveNQueens() {
    const board = Array.from({ length: N }, () => Array(N).fill(0));

    if (!solveNQueensHelper(board, 0)) {
        console.log("Solution does not exist");
        return;
    }

    console.log("=== Final Solution Found ===");
    printBoard(board);
}

function main() {
    console.log(`=== Backtracking: N-Queens Solver (N = ${N}) ===\n`);
    solveNQueens();

    const rl = readline.createInterface({
        input: process.stdin,
        output: process.stdout
    });
    rl.question("Press Enter to exit...", () => {
        rl.close();
    });
}

main();
