import Foundation

func demonstrateConstantTime(_ n: Int) {
    var operations = 0
    let a = 10
    operations += 1
    let b = 20
    operations += 1
    let _ = a + b
    operations += 1
    print("O(1) Constant Time:")
    print("  Input size (n): \(n)")
    print("  Actual operations counted: \(operations)\n")
}

func demonstrateLogarithmicTime(_ n: Int) {
    var operations = 0
    var temp = n
    print("O(log n) Logarithmic Time:")
    print("  Dividing input size \(n) by 2 repeatedly:")
    while temp > 1 {
        print("    Current value: \(temp)")
        temp /= 2
        operations += 1
    }
    print("  Input size (n): \(n)")
    print("  Actual operations counted: \(operations)\n")
}

func demonstrateLinearTime(_ n: Int) {
    var operations = 0
    for _ in 0..<n {
        operations += 1
    }
    print("O(n) Linear Time:")
    print("  Input size (n): \(n)")
    print("  Actual operations counted: \(operations)\n")
}

func demonstrateLinearithmicTime(_ n: Int) {
    var operations = 0
    for _ in 0..<n {
        var temp = n
        while temp > 1 {
            temp /= 2
            operations += 1
        }
    }
    print("O(n log n) Linearithmic Time:")
    print("  Input size (n): \(n)")
    print("  Actual operations counted: \(operations)\n")
}

func demonstrateQuadraticTime(_ n: Int) {
    var operations = 0
    for _ in 0..<n {
        for _ in 0..<n {
            operations += 1
        }
    }
    print("O(n^2) Quadratic Time:")
    print("  Input size (n): \(n)")
    print("  Actual operations counted: \(operations) (n * n)\n")
}

func main() {
    let n = 16
    print("=== Time Complexity Visualizer ===")
    print("This program counts operations to demonstrate theoretical time complexities.\n")
    demonstrateConstantTime(n)
    demonstrateLogarithmicTime(n)
    demonstrateLinearTime(n)
    demonstrateLinearithmicTime(n)
    demonstrateQuadraticTime(n)
    print("Press Enter to exit...", terminator: "")
    fflush(stdout)
    let _ = readLine()
}

main()
