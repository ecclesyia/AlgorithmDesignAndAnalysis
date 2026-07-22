import java.util.Scanner;

public class complexity_examples {
    public static void demonstrateConstantTime(int n) {
        int operations = 0;
        int a = 10;
        operations++;
        int b = 20;
        operations++;
        int sum = a + b;
        operations++;
        System.out.println("O(1) Constant Time:");
        System.out.println("  Input size (n): " + n);
        System.out.println("  Actual operations counted: " + operations + "\n");
    }

    public static void demonstrateLogarithmicTime(int n) {
        int operations = 0;
        int temp = n;
        System.out.println("O(log n) Logarithmic Time:");
        System.out.println("  Dividing input size " + n + " by 2 repeatedly:");
        while (temp > 1) {
            System.out.println("    Current value: " + temp);
            temp /= 2;
            operations++;
        }
        System.out.println("  Input size (n): " + n);
        System.out.println("  Actual operations counted: " + operations + "\n");
    }

    public static void demonstrateLinearTime(int n) {
        int operations = 0;
        for (int i = 0; i < n; i++) {
            operations++;
        }
        System.out.println("O(n) Linear Time:");
        System.out.println("  Input size (n): " + n);
        System.out.println("  Actual operations counted: " + operations + "\n");
    }

    public static void demonstrateLinearithmicTime(int n) {
        int operations = 0;
        for (int i = 0; i < n; i++) {
            int temp = n;
            while (temp > 1) {
                temp /= 2;
                operations++;
            }
        }
        System.out.println("O(n log n) Linearithmic Time:");
        System.out.println("  Input size (n): " + n);
        System.out.println("  Actual operations counted: " + operations + "\n");
    }

    public static void demonstrateQuadraticTime(int n) {
        int operations = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                operations++;
            }
        }
        System.out.println("O(n^2) Quadratic Time:");
        System.out.println("  Input size (n): " + n);
        System.out.println("  Actual operations counted: " + operations + " (n * n)\n");
    }

    public static void main(String[] args) {
        int n = 16;
        System.out.println("=== Time Complexity Visualizer ===");
        System.out.println("This program counts operations to demonstrate theoretical time complexities.\n");
        demonstrateConstantTime(n);
        demonstrateLogarithmicTime(n);
        demonstrateLinearTime(n);
        demonstrateLinearithmicTime(n);
        demonstrateQuadraticTime(n);
        System.out.print("Press Enter to exit...");
        Scanner scanner = new Scanner(System.in);
        scanner.nextLine();
        scanner.close();
    }
}
