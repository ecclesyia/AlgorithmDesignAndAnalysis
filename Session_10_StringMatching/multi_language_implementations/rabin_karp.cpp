// Session 10: Rabin-Karp String Matching in C++

#include <iostream>
#include <string>

#define d 256
#define q 101

void runRabinKarp(const std::string &pat, const std::string &txt) {
    int M = pat.length();
    int N = txt.length();
    int p = 0, t = 0, h = 1;

    for (int i = 0; i < M - 1; i++) {
        h = (h * d) % q;
    }

    for (int i = 0; i < M; i++) {
        p = (d * p + pat[i]) % q;
        t = (d * t + txt[i]) % q;
    }

    for (int i = 0; i <= N - M; i++) {
        if (p == t) {
            int j;
            for (j = 0; j < M; j++) {
                if (txt[i + j] != pat[j]) {
                    break;
                }
            }
            if (j == M) {
                std::cout << "Pattern found at index " << i << "\n";
            }
        }
        if (i < N - M) {
            t = (d * (t - txt[i] * h) + txt[i + M]) % q;
            if (t < 0) {
                t = (t + q);
            }
        }
    }
}

int main() {
    std::string txt = "GEEKS FOR GEEKS";
    std::string pat = "GEEK";
    runRabinKarp(pat, txt);
    return 0;
}
