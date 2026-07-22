// Session 10: Rabin-Karp String Matching in Java

public class rabin_karp {
    private static final int d = 256;
    private static final int q = 101;

    public static void runRabinKarp(String pat, String txt) {
        int M = pat.length();
        int N = txt.length();
        int p = 0;
        int t = 0;
        int h = 1;

        for (int i = 0; i < M - 1; i++) {
            h = (h * d) % q;
        }

        for (int i = 0; i < M; i++) {
            p = (d * p + pat.charAt(i)) % q;
            t = (d * t + txt.charAt(i)) % q;
        }

        for (int i = 0; i <= N - M; i++) {
            if (p == t) {
                int j;
                for (j = 0; j < M; j++) {
                    if (txt.charAt(i + j) != pat.charAt(j)) {
                        break;
                    }
                }
                if (j == M) {
                    System.out.println("Pattern found at index " + i);
                }
            }

            if (i < N - M) {
                t = (d * (t - txt.charAt(i) * h) + txt.charAt(i + M)) % q;
                if (t < 0) {
                    t = (t + q);
                }
            }
        }
    }

    public static void main(String[] args) {
        String txt = "GEEKS FOR GEEKS";
        String pat = "GEEK";
        runRabinKarp(pat, txt);
    }
}
// Note: Class name rabin_karp is lowercase to match rabin_karp.java filename exactly.
