// Session 10: Knuth-Morris-Pratt (KMP) String Matching in C++

#include <iostream>
#include <string>
#include <vector>

void computeLPSArray(const std::string &pat, int M, std::vector<int> &lps) {
    int len = 0;
    lps[0] = 0;
    int i = 1;
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

void runKMP(const std::string &pat, const std::string &txt) {
    int M = pat.length();
    int N = txt.length();
    std::vector<int> lps(M);
    computeLPSArray(pat, M, lps);
    
    int i = 0, j = 0;
    while ((N - i) >= (M - j)) {
        if (pat[j] == txt[i]) {
            i++;
            j++;
        }
        if (j == M) {
            std::cout << "Pattern found at index " << (i - j) << "\n";
            j = lps[j - 1];
        } else if (i < N && pat[j] != txt[i]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }
}

int main() {
    std::string txt = "ABABDABACDABABCABAB";
    std::string pat = "ABABCABAB";
    runKMP(pat, txt);
    return 0;
}
