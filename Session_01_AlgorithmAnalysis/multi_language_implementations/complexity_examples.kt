import java.util.Scanner

fun demonstrateConstantTime(n: Int) {
    var operations = 0
    val a = 10
    operations++
    val b = 20
    operations++
    val sum = a + b
    operations++
    println("O(1) Constant Time:")
    println("  Input size (n): $n")
    println("  Actual operations counted: $operations\n")
}

fun demonstrateLogarithmicTime(n: Int) {
    var operations = 0
    var temp = n
    println("O(log n) Logarithmic Time:")
    println("  Dividing input size $n by 2 repeatedly:")
    while (temp > 1) {
        println("    Current value: $temp")
        temp /= 2
        operations++
    }
    println("  Input size (n): $n")
    println("  Actual operations counted: $operations\n")
}

fun demonstrateLinearTime(n: Int) {
    var operations = 0
    for (i in 0 until n) {
        operations++
    }
    println("O(n) Linear Time:")
    println("  Input size (n): $n")
    println("  Actual operations counted: $operations\n")
}

fun demonstrateLinearithmicTime(n: Int) {
    var operations = 0
    for (i in 0 until n) {
        var temp = n
        while (temp > 1) {
            temp /= 2
            operations++
        }
    }
    println("O(n log n) Linearithmic Time:")
    println("  Input size (n): $n")
    println("  Actual operations counted: $operations\n")
}

fun demonstrateQuadraticTime(n: Int) {
    var operations = 0
    for (i in 0 until n) {
        for (j in 0 until n) {
            operations++
        }
    }
    println("O(n^2) Quadratic Time:")
    println("  Input size (n): $n")
    println("  Actual operations counted: $operations (n * n)\n")
}

fun main() {
    val n = 16
    println("=== Time Complexity Visualizer ===")
    println("This program counts operations to demonstrate theoretical time complexities.\n")
    demonstrateConstantTime(n)
    demonstrateLogarithmicTime(n)
    demonstrateLinearTime(n)
    demonstrateLinearithmicTime(n)
    demonstrateQuadraticTime(n)
    print("Press Enter to exit...")
    Scanner(System.`in`).nextLine()
}
