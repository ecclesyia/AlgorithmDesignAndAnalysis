fun computeLPSArray(pat: String, M: Int, lps: IntArray) {
    var lenPrev = 0
    lps[0] = 0
    var i = 1

    while (i < M) {
        if (pat[i] == pat[lenPrev]) {
            lenPrev++
            lps[i] = lenPrev
            i++
        } else {
            if (lenPrev != 0) {
                lenPrev = lps[lenPrev - 1]
            } else {
                lps[i] = 0
                i++
            }
        }
    }
}

fun runKMP(pat: String, txt: String) {
    val M = pat.length
    val N = txt.length
    val lps = IntArray(M)

    computeLPSArray(pat, M, lps)

    println("Precomputed LPS Table for pattern \"$pat\":")
    print("  Char: ")
    for (i in 0 until M) {
        print("${pat[i]} ")
    }
    println()
    print("  LPS:  ")
    for (i in 0 until M) {
        print("${lps[i]} ")
    }
    println("\n")

    var i = 0
    var j = 0

    println("KMP Search steps:")
    while ((N - i) >= (M - j)) {
        if (pat[j] == txt[i]) {
            i++
            j++
        }

        if (j == M) {
            println("  Pattern found at index: ${i - j}")
            j = lps[j - 1]
        } else if (i < N && pat[j] != txt[i]) {
            if (j != 0) {
                println("  Mismatch at txt[$i] ('${txt[i]}') and pat[$j] ('${pat[j]}'). Sliding to pat[${lps[j - 1]}]")
                j = lps[j - 1]
            } else {
                i++
            }
        }
    }
}

fun main() {
    val txt = "ABABDABACDABABCABAB"
    val pat = "ABABCABAB"

    println("=== Knuth-Morris-Pratt (KMP) Search ===")
    println("Text: \"$txt\"")
    println("Pattern: \"$pat\"\n")

    runKMP(pat, txt)

    println()
    print("Press Enter to exit...")
    readLine()
}
