#include <iostream>
#include <string>

void printIndent(int depth) {
    for (int i = 0; i < depth; i++) {
        std::cout << "  |  ";
    }
}

long long calculateFactorial(int n, int depth) {
    printIndent(depth);
    std::cout << "Entering factorial(" << n << "). Address of n: " << (void*)&n << "\n";
    if (n <= 1) {
        printIndent(depth);
        std::cout << "Base Case reached for factorial(" << n << "). Returning 1.\n";
        return 1;
    }
    long long subResult = calculateFactorial(n - 1, depth + 1);
    long long result = n * subResult;
    printIndent(depth);
    std::cout << "Exiting factorial(" << n << ") -> returning " << n << " * " << subResult << " = " << result << "\n";
    return result;
}

int calculateFibonacci(int n, int depth, const std::string &branch) {
    printIndent(depth);
    std::cout << "Entering fibonacci(" << n << ") [" << branch << " branch]. Address of n: " << (void*)&n << "\n";
    if (n == 0) {
        printIndent(depth);
        std::cout << "Base Case: fibonacci(0) = 0. Returning.\n";
        return 0;
    }
    if (n == 1) {
        printIndent(depth);
        std::cout << "Base Case: fibonacci(1) = 1. Returning.\n";
        return 1;
    }
    int left = calculateFibonacci(n - 1, depth + 1, "Left");
    int right = calculateFibonacci(n - 2, depth + 1, "Right");
    int result = left + right;
    printIndent(depth);
    std::cout << "Exiting fibonacci(" << n << ") -> returning " << left << " + " << right << " = " << result << "\n";
    return result;
}

int main() {
    int val = 5;
    std::cout << "=== Recursion & Stack Frame Visualizer ===\n\n";
    std::cout << "--- PART 1: Linear Recursion - Factorial(" << val << ") ---\n";
    long long fact = calculateFactorial(val, 0);
    std::cout << "\nFactorial of " << val << " is: " << fact << "\n\n";
    std::cout << "--------------------------------------------------\n\n";
    std::cout << "--- PART 2: Tree Recursion - Fibonacci(4) ---\n";
    int fib = calculateFibonacci(4, 0, "Root");
    std::cout << "\nFibonacci of 4 is: " << fib << "\n\n";
    std::cout << "Press Enter to exit...";
    std::cin.get();
    return 0;
}
