import java.util.Scanner;

public class recurrence_analysis {
    private static void printIndent(int depth) {
        for (int i = 0; i < depth; i++) {
            System.out.print("  |  ");
        }
    }

    private static String getAddress(int depth) {
        long base = 0x7ffebfaf1000L;
        return "0x" + Long.toHexString(base - depth * 0x30L);
    }

    public static long calculateFactorial(int n, int depth) {
        printIndent(depth);
        System.out.println("Entering factorial(" + n + "). Address of n: " + getAddress(depth));
        if (n <= 1) {
            printIndent(depth);
            System.out.println("Base Case reached for factorial(" + n + "). Returning 1.");
            return 1;
        }
        long subResult = calculateFactorial(n - 1, depth + 1);
        long result = n * subResult;
        printIndent(depth);
        System.out.println("Exiting factorial(" + n + ") -> returning " + n + " * " + subResult + " = " + result);
        return result;
    }

    public static int calculateFibonacci(int n, int depth, String branch) {
        printIndent(depth);
        System.out.println("Entering fibonacci(" + n + ") [" + branch + " branch]. Address of n: " + getAddress(depth));
        if (n == 0) {
            printIndent(depth);
            System.out.println("Base Case: fibonacci(0) = 0. Returning.");
            return 0;
        }
        if (n == 1) {
            printIndent(depth);
            System.out.println("Base Case: fibonacci(1) = 1. Returning.");
            return 1;
        }
        int left = calculateFibonacci(n - 1, depth + 1, "Left");
        int right = calculateFibonacci(n - 2, depth + 1, "Right");
        int result = left + right;
        printIndent(depth);
        System.out.println("Exiting fibonacci(" + n + ") -> returning " + left + " + " + right + " = " + result);
        return result;
    }

    public static void main(String[] args) {
        int val = 5;
        System.out.println("=== Recursion & Stack Frame Visualizer ===\n");
        System.out.println("--- PART 1: Linear Recursion - Factorial(" + val + ") ---");
        long fact = calculateFactorial(val, 0);
        System.out.println("\nFactorial of " + val + " is: " + fact + "\n");
        System.out.println("--------------------------------------------------\n");
        System.out.println("--- PART 2: Tree Recursion - Fibonacci(4) ---");
        int fib = calculateFibonacci(4, 0, "Root");
        System.out.println("\nFibonacci of 4 is: " + fib + "\n");
        System.out.print("Press Enter to exit...");
        Scanner scanner = new Scanner(System.in);
        scanner.nextLine();
        scanner.close();
    }
}
