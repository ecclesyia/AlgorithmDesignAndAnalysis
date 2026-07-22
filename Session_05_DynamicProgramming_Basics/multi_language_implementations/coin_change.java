import java.util.Scanner;

public class coin_change {
    private static final int INF = (int)1e9;

    public static int getMinCoins(int[] coins, int amount) {
        int[] dp = new int[amount + 1];
        dp[0] = 0;
        for (int i = 1; i <= amount; i++) {
            dp[i] = INF;
        }

        for (int i = 1; i <= amount; i++) {
            for (int j = 0; j < coins.length; j++) {
                if (coins[j] <= i) {
                    int subRes = dp[i - coins[j]];
                    if (subRes != INF && subRes + 1 < dp[i]) {
                        dp[i] = subRes + 1;
                    }
                }
            }
        }

        int result = dp[amount];
        return (result == INF) ? -1 : result;
    }

    public static void main(String[] args) {
        int[] coins = {1, 3, 4};
        int amount = 6;
        System.out.println("Min coins required: " + getMinCoins(coins, amount));
        System.out.println();
        System.out.print("Press Enter to exit...");
        Scanner scanner = new Scanner(System.in);
        scanner.nextLine();
        scanner.close();
    }
}
