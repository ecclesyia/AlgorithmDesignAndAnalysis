#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

void solveLCS(const std::string &s1, const std::string &s2) {
    int m = s1.length();
    int n = s2.length();
    std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0) dp[i][j] = 0;
            else if (s1[i - 1] == s2[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
            else dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    std::cout << "LCS Length: " << dp[m][n] << "\n";
    int index = dp[m][n];
    std::string lcsStr(index, ' ');
    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (s1[i - 1] == s2[j - 1]) {
            lcsStr[index - 1] = s1[i - 1];
            i--; j--; index--;
        } else if (dp[i - 1][j] > dp[i][j - 1]) i--;
        else j--;
    }
    std::cout << "LCS String: " << lcsStr << "\n";
}

int main() {
    std::string s1 = "STONE";
    std::string s2 = "LONEST";
    solveLCS(s1, s2);
    std::cout << "\nPress Enter to exit...";
    std::cin.get();
    return 0;
}
