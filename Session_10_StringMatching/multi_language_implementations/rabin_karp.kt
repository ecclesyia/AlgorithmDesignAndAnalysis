const val d = 256
const val q = 101

fun runRabinKarp(pat: String, txt: String) {
    val M = pat.length
    val N = txt.length
    var p = 0
    var t = 0
    var h = 1

    for (i in 0 until M - 1) {
        h = (h * d) % q
    }

    for (i in 0 until M) {
        p = (d * p + pat[i].code) % q
        t = (d * t + txt[i].code) % q
    }

    println("Rabin-Karp Search details:")
    println("  Pattern hash: $p")

    for (i in 0..N - M) {
        if (p == t) {
            println("  Hash match found at index $i (hash: $t). Checking characters...")
            var j = 0
            while (j < M) {
                if (txt[i + j] != pat[j]) {
                    break
                }
                j++
            }
            if (j == M) {
                println("    Pattern found at index: $i")
            }
        }

        if (i < N - M) {
            t = (d * (t - txt[i].code * h) + txt[i + M].code) % q
            if (t < 0) {
                t += q
            }
        }
    }
}

fun main() {
    val txt = "GEEKS FOR GEEKS"
    val pat = "GEEK"

    println("=== Rabin-Karp String Search ===")
    println("Text: \"$txt\"")
    println("Pattern: \"$pat\"\n")

    runRabinKarp(pat, txt)

    println()
    print("Press Enter to exit...")
    readLine()
}
