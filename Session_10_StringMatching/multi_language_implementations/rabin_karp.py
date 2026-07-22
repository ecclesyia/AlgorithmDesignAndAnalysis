# Session 10: Rabin-Karp String Matching in Python

d = 256
q = 101

def run_rabin_karp(pat, txt):
    M = len(pat)
    N = len(txt)
    p = 0
    t = 0
    h = 1
    
    for i in range(M - 1):
        h = (h * d) % q
        
    for i in range(M):
        p = (d * p + ord(pat[i])) % q
        t = (d * t + ord(txt[i])) % q
        
    for i in range(N - M + 1):
        if p == t:
            j = 0
            while j < M:
                if txt[i + j] != pat[j]:
                    break
                j += 1
            if j == M:
                print(f"Pattern found at index {i}")
                
        if i < N - M:
            t = (d * (t - ord(txt[i]) * h) + ord(txt[i + M])) % q
            if t < 0:
                t = t + q

def main():
    txt = "GEEKS FOR GEEKS"
    pat = "GEEK"
    run_rabin_karp(pat, txt)

if __name__ == "__main__":
    main()
