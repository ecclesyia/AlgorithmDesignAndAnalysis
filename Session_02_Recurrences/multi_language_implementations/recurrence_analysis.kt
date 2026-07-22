import java.util.Scanner

fun printIndent(depth: Int) {
    for (i in 0 until depth) {
        print("  |  ")
    }
}

fun calculateFactorial(n: Int, depth: Int): Long {
    printIndent(depth)
    val address = "0x" + Integer.toHexString(System.identityHashCode(n))
    println("Entering factorial($n). Address of n: $address")
    if (n <= 1) {
        printIndent(depth)
        println("Base Case reached for factorial($n). Returning 1.")
        return 1
    }
    val subResult = calculateFactorial(n - 1, depth + 1)
    val result = n * subResult
    printIndent(depth)
    println("Exiting factorial($n) -> returning $n * $subResult = $result")
    return result
}

fun calculateFibonacci(n: Int, depth: Int, branch: String): Int {
    printIndent(depth)
    val address = "0x" + Integer.toHexString(System.identityHashCode(n))
    println("Entering fibonacci($n) [$branch branch]. Address of n: $address")
    if (n == 0) {
        printIndent(depth)
        println("Base Case: fibonacci(0) = 0. Returning.")
        return 0
    }
    if (n == 1) {
        printIndent(depth)
        println("Base Case: fibonacci(1) = 1. Returning.")
        return 1
    }
    val left = calculateFibonacci(n - 1, depth + 1, "Left")
    val right = calculateFibonacci(n - 2, depth + 1, "Right")
    val result = left + right
    printIndent(depth)
    println("Exiting fibonacci($n) -> returning $left + $right = $result")
    return result
}

fun main() {
    val valSize = 5
    println("=== Recursion & Stack Frame Visualizer ===\n")
    println("--- PART 1: Linear Recursion - Factorial($valSize) ---")
    val fact = calculateFactorial(valSize, 0)
    println("\nFactorial of $valSize is: $fact\n")
    println("--------------------------------------------------\n")
    println("--- PART 2: Tree Recursion - Fibonacci(4) ---")
    val fib = calculateFibonacci(4, 0, "Root")
    println("\nFibonacci of 4 is: $fib\n")
    print("Press Enter to exit...")
    Scanner(System.`in`).nextLine()
}
