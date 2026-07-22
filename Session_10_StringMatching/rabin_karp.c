#include <stdio.h>
#include <string.h>

/*
 * Session 10: Rabin-Karp String Matching in C
 * Uses a rolling hash function to search for a pattern in a text.
 * Time Complexity: O(n + m) average, O(n * m) worst-case (due to collisions)
 * Space Complexity: O(1)
 */

#define d 256 // Number of characters in input alphabet
#define q 101 // A prime number for modulo arithmetic hash bounds

void runRabinKarp(char pat[], char txt[]) {
    int M = strlen(pat);
    int N = strlen(txt);
    int i, j;
    int p = 0; // hash value for pattern
    int t = 0; // hash value for txt
    int h = 1;

    // The value of h would be "pow(d, M-1) %% q"
    for (i = 0; i < M - 1; i++) {
        h = (h * d) % q;
    }

    // Calculate the initial hash value of pattern and first window of text
    for (i = 0; i < M; i++) {
        p = (d * p + pat[i]) % q;
        t = (d * t + txt[i]) % q;
    }

    printf("Rabin-Karp Search details:\n");
    printf("  Pattern hash: %d\n", p);

    // Slide the pattern over text one by one
    for (i = 0; i <= N - M; i++) {
        // Check the hash values of current window of text and pattern.
        // If the hash values match then only check for characters one by one.
        if (p == t) {
            printf("  Hash match found at index %d (hash: %d). Checking characters...\n", i, t);
            
            /* Check for characters one by one */
            for (j = 0; j < M; j++) {
                if (txt[i + j] != pat[j])
                    break;
            }

            // if p == t and pat[0...M-1] = txt[i, i+1, ...i+M-1]
            if (j == M) {
                printf("    Pattern found at index: %d\n", i);
            }
        }

        // Calculate hash value for next window of text: Remove leading digit, add trailing digit
        if (i < N - M) {
            t = (d * (t - txt[i] * h) + txt[i + M]) % q;

            // We might get negative value of t, converting it to positive
            if (t < 0) {
                t = (t + q);
            }
        }
    }
}

int main() {
    char txt[] = "GEEKS FOR GEEKS";
    char pat[] = "GEEK";

    printf("=== Rabin-Karp String Search ===\n");
    printf("Text: \"%s\"\n", txt);
    printf("Pattern: \"%s\"\n\n", pat);

    runRabinKarp(pat, txt);

    printf("\nPress Enter to exit...");
    getchar();
    return 0;
}
