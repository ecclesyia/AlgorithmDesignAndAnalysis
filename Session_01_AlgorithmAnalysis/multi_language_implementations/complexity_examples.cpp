#include <iostream>

void demonstrateConstantTime(int n) {
    int operations = 0;
    int a = 10;
    operations++;
    int b = 20;
    operations++;
    int sum = a + b;
    operations++;
    std::cout << "O(1) Constant Time:\n";
    std::cout << "  Input size (n): " << n << "\n";
    std::cout << "  Actual operations counted: " << operations << "\n\n";
}

void demonstrateLogarithmicTime(int n) {
    int operations = 0;
    int temp = n;
    std::cout << "O(log n) Logarithmic Time:\n";
    std::cout << "  Dividing input size " << n << " by 2 repeatedly:\n";
    while (temp > 1) {
        std::cout << "    Current value: " << temp << "\n";
        temp /= 2;
        operations++;
    }
    std::cout << "  Input size (n): " << n << "\n";
    std::cout << "  Actual operations counted: " << operations << "\n\n";
}

void demonstrateLinearTime(int n) {
    int operations = 0;
    for (int i = 0; i < n; i++) {
        operations++;
    }
    std::cout << "O(n) Linear Time:\n";
    std::cout << "  Input size (n): " << n << "\n";
    std::cout << "  Actual operations counted: " << operations << "\n\n";
}

void demonstrateLinearithmicTime(int n) {
    int operations = 0;
    for (int i = 0; i < n; i++) {
        int temp = n;
        while (temp > 1) {
            temp /= 2;
            operations++;
        }
    }
    std::cout << "O(n log n) Linearithmic Time:\n";
    std::cout << "  Input size (n): " << n << "\n";
    std::cout << "  Actual operations counted: " << operations << "\n\n";
}

void demonstrateQuadraticTime(int n) {
    int operations = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            operations++;
        }
    }
    std::cout << "O(n^2) Quadratic Time:\n";
    std::cout << "  Input size (n): " << n << "\n";
    std::cout << "  Actual operations counted: " << operations << " (n * n)\n\n";
}

int main() {
    int n = 16;
    std::cout << "=== Time Complexity Visualizer ===\n";
    std::cout << "This program counts operations to demonstrate theoretical time complexities.\n\n";
    demonstrateConstantTime(n);
    demonstrateLogarithmicTime(n);
    demonstrateLinearTime(n);
    demonstrateLinearithmicTime(n);
    demonstrateQuadraticTime(n);
    std::cout << "Press Enter to exit...";
    std::cin.get();
    return 0;
}
