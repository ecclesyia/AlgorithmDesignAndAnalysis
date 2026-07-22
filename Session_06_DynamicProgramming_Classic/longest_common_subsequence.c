#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * Session 06: Longest Common Subsequence in C
 * Builds a 2D table to calculate the LCS of two strings and backtracks
 * to reconstruct and print the subsequence characters.
 * Time Complexity: O(m * n)
 * Space Complexity: O(m * n)
 */

int max(int a, int b) {
    return (a > b) ? a : b;
}

void solveLCS(char *s1, char *s2) {
    int m = strlen(s1);
    int n = strlen(s2);

    // Allocate 2D DP table
    int **dp = (int **)malloc((m + 1) * sizeof(int *));
    for (int i = 0; i <= m; i++) {
        dp[i] = (int *)malloc((n + 1) * sizeof(int));
    }

    // Initialize and fill the DP table
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0) {
                dp[i][j] = 0;
            } else if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    printf("DP Table:\n      ");
    for (int j = 0; j < n; j++) {
        printf("%c  ", s2[j]);
    }
    printf("\n");
    for (int i = 0; i <= m; i++) {
        if (i > 0) printf("%c ", s1[i - 1]);
        else printf("- ");
        for (int j = 0; j <= n; j++) {
            printf("%d  ", dp[i][j]);
        }
        printf("\n");
    }
    printf("\nLCS Length: %d\n", dp[m][n]);

    // Backtrack to find the actual subsequence string
    int index = dp[m][n];
    char *lcsStr = (char *)malloc((index + 1) * sizeof(char));
    lcsStr[index] = '\0'; // Null terminator

    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (s1[i - 1] == s2[j - 1]) {
            lcsStr[index - 1] = s1[i - 1]; // Character belongs to LCS
            i--;
            j--;
            index--;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }

    printf("Reconstructed LCS String: %s\n", lcsStr);

    // Free memory
    free(lcsStr);
    for (int r = 0; r <= m; r++) {
        free(dp[r]);
    }
    free(dp);
}

int main() {
    char s1[] = "STONE";
    char s2[] = "LONEST";

    printf("=== Dynamic Programming: Longest Common Subsequence ===\n");
    printf("String 1: %s\n", s1);
    printf("String 2: %s\n\n", s2);

    solveLCS(s1, s2);

    printf("\nPress Enter to exit...");
    getchar();
    return 0;
}
