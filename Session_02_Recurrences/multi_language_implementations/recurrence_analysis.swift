import Foundation

func printIndent(_ depth: Int) {
    for _ in 0..<depth {
        print("  |  ", terminator: "")
    }
}

func calculateFactorial(_ n: Int, _ depth: Int) -> Int64 {
    printIndent(depth)
    var temp = n
    let address = withUnsafePointer(to: &temp) { "\($0)" }
    print("Entering factorial(\(n)). Address of n: \(address)")
    if n <= 1 {
        printIndent(depth)
        print("Base Case reached for factorial(\(n)). Returning 1.")
        return 1
    }
    let subResult = calculateFactorial(n - 1, depth + 1)
    let result = Int64(n) * subResult
    printIndent(depth)
    print("Exiting factorial(\(n)) -> returning \(n) * \(subResult) = \(result)")
    return result
}

func calculateFibonacci(_ n: Int, _ depth: Int, _ branch: String) -> Int {
    printIndent(depth)
    var temp = n
    let address = withUnsafePointer(to: &temp) { "\($0)" }
    print("Entering fibonacci(\(n)) [\(branch) branch]. Address of n: \(address)")
    if n == 0 {
        printIndent(depth)
        print("Base Case: fibonacci(0) = 0. Returning.")
        return 0
    }
    if n == 1 {
        printIndent(depth)
        print("Base Case: fibonacci(1) = 1. Returning.")
        return 1
    }
    let left = calculateFibonacci(n - 1, depth + 1, "Left")
    let right = calculateFibonacci(n - 2, depth + 1, "Right")
    let result = left + right
    printIndent(depth)
    print("Exiting fibonacci(\(n)) -> returning \(left) + \(right) = \(result)")
    return result
}

func main() {
    let val = 5
    print("=== Recursion & Stack Frame Visualizer ===\n")
    print("--- PART 1: Linear Recursion - Factorial(\(val)) ---")
    let fact = calculateFactorial(val, 0)
    print("\nFactorial of \(val) is: \(fact)\n")
    print("--------------------------------------------------\n")
    print("--- PART 2: Tree Recursion - Fibonacci(4) ---")
    let fib = calculateFibonacci(4, 0, "Root")
    print("\nFibonacci of 4 is: \(fib)\n")
    print("Press Enter to exit...", terminator: "")
    fflush(stdout)
    let _ = readLine()
}

main()
