import sys

def solve_lcs(s1, s2):
    m = len(s1)
    n = len(s2)
    dp = [[0] * (n + 1) for _ in range(m + 1)]
    for i in range(m + 1):
        for j in range(n + 1):
            if i == 0 or j == 0:
                dp[i][j] = 0
            elif s1[i - 1] == s2[j - 1]:
                dp[i][j] = dp[i - 1][j - 1] + 1
            else:
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1])
                
    print(f"LCS Length: {dp[m][n]}")
    
    index = dp[m][n]
    lcs_chars = [""] * index
    i, j = m, n
    while i > 0 and j > 0:
        if s1[i - 1] == s2[j - 1]:
            lcs_chars[index - 1] = s1[i - 1]
            i -= 1
            j -= 1
            index -= 1
        elif dp[i - 1][j] > dp[i][j - 1]:
            i -= 1
        else:
            j -= 1
            
    lcs_str = "".join(lcs_chars)
    print(f"LCS String: {lcs_str}")

def main():
    s1 = "STONE"
    s2 = "LONEST"
    solve_lcs(s1, s2)
    print()
    input("Press Enter to exit...")

if __name__ == "__main__":
    main()
