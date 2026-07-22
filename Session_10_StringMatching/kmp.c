#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * Session 10: Knuth-Morris-Pratt (KMP) Algorithm in C
 * Uses a precomputed LPS (Longest Proper Prefix which is also a Suffix) array.
 * Time Complexity: O(n + m)
 * Space Complexity: O(m) for the LPS array
 */

// Precompute the LPS array for the pattern
void computeLPSArray(char pat[], int M, int lps[]) {
    int len = 0; // Length of the previous longest prefix suffix
    lps[0] = 0;  // lps[0] is always 0
    int i = 1;

    // Loop calculates lps[i] for i = 1 to M-1
    while (i < M) {
        if (pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

void runKMP(char pat[], char txt[]) {
    int M = strlen(pat);
    int N = strlen(txt);

    // Create lps[] that will hold the longest prefix suffix values for pattern
    int *lps = (int *)malloc(M * sizeof(int));

    // Precompute the lps array
    computeLPSArray(pat, M, lps);

    // Print the computed LPS array for the student's study
    printf("Precomputed LPS Table for pattern \"%s\":\n", pat);
    printf("  Char: ");
    for (int i = 0; i < M; i++) {
        printf("%c ", pat[i]);
    }
    printf("\n  LPS:  ");
    for (int i = 0; i < M; i++) {
        printf("%d ", lps[i]);
    }
    printf("\n\n");

    int i = 0; // Index for txt[]
    int j = 0; // Index for pat[]
    
    printf("KMP Search steps:\n");
    while ((N - i) >= (M - j)) {
        if (pat[j] == txt[i]) {
            i++;
            j++;
        }

        if (j == M) {
            printf("  Pattern found at index: %d\n", i - j);
            j = lps[j - 1]; // Reset pattern index using LPS table
        }
        // Mismatch after j matches
        else if (i < N && pat[j] != txt[i]) {
            // Do not match lps[0..lps[j-1]] characters, they will match anyway
            if (j != 0) {
                printf("  Mismatch at txt[%d] ('%c') and pat[%d] ('%c'). Sliding to pat[%d]\n",
                       i, txt[i], j, pat[j], lps[j - 1]);
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }

    free(lps);
}

int main() {
    char txt[] = "ABABDABACDABABCABAB";
    char pat[] = "ABABCABAB";

    printf("=== Knuth-Morris-Pratt (KMP) Search ===\n");
    printf("Text: \"%s\"\n", txt);
    printf("Pattern: \"%s\"\n\n", pat);

    runKMP(pat, txt);

    printf("\nPress Enter to exit...");
    getchar();
    return 0;
}
