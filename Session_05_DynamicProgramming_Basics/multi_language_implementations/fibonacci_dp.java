import java.util.Arrays;
import java.util.Scanner;

public class fibonacci_dp {
    public static long fibNaive(int n) {
        if (n <= 1) {
            return n;
        }
        return fibNaive(n - 1) + fibNaive(n - 2);
    }

    private static long fibMemoizeHelper(int n, long[] memo) {
        if (memo[n] != -1) {
            return memo[n];
        }
        if (n <= 1) {
            memo[n] = n;
            return n;
        }
        memo[n] = fibMemoizeHelper(n - 1, memo) + fibMemoizeHelper(n - 2, memo);
        return memo[n];
    }

    public static long fibMemoization(int n) {
        long[] memo = new long[n + 1];
        Arrays.fill(memo, -1);
        return fibMemoizeHelper(n, memo);
    }

    public static long fibTabulation(int n) {
        if (n <= 1) {
            return n;
        }
        long[] table = new long[n + 1];
        table[0] = 0;
        table[1] = 1;
        for (int i = 2; i <= n; i++) {
            table[i] = table[i - 1] + table[i - 2];
        }
        return table[n];
    }

    public static void main(String[] args) {
        int n = 35;
        System.out.println("Fib(" + n + ") Naive: " + fibNaive(n));
        System.out.println("Fib(" + n + ") Memo: " + fibMemoization(n));
        System.out.println("Fib(" + n + ") Tab: " + fibTabulation(n));
        System.out.println();
        System.out.print("Press Enter to exit...");
        Scanner scanner = new Scanner(System.in);
        scanner.nextLine();
        scanner.close();
    }
}
