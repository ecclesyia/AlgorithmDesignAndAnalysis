import Foundation

func computeLPSArray(_ pat: [Character], _ M: Int, _ lps: inout [Int]) {
    var lenPrev = 0
    lps[0] = 0
    var i = 1
    
    while i < M {
        if pat[i] == pat[lenPrev] {
            lenPrev += 1
            lps[i] = lenPrev
            i += 1
        } else {
            if lenPrev != 0 {
                lenPrev = lps[lenPrev - 1]
            } else {
                lps[i] = 0
                i += 1
            }
        }
    }
}

func runKMP(_ pat: String, _ txt: String) {
    let patChars = Array(pat)
    let txtChars = Array(txt)
    let M = patChars.count
    let N = txtChars.count
    var lps = Array(repeating: 0, count: M)
    
    computeLPSArray(patChars, M, &lps)
    
    print("Precomputed LPS Table for pattern \"\(pat)\":")
    print("  Char: ", terminator: "")
    for i in 0..<M {
        print("\(patChars[i]) ", terminator: "")
    }
    print()
    print("  LPS:  ", terminator: "")
    for i in 0..<M {
        print("\(lps[i]) ", terminator: "")
    }
    print("\n")
    
    var i = 0
    var j = 0
    
    print("KMP Search steps:")
    while (N - i) >= (M - j) {
        if patChars[j] == txtChars[i] {
            i += 1
            j += 1
        }
        
        if j == M {
            print("  Pattern found at index: \(i - j)")
            j = lps[j - 1]
        } else if i < N && patChars[j] != txtChars[i] {
            if j != 0 {
                print("  Mismatch at txt[\(i)] ('\(txtChars[i])') and pat[\(j)] ('\(patChars[j])'). Sliding to pat[\(lps[j - 1])]")
                j = lps[j - 1]
            } else {
                i += 1
            }
        }
    }
}

func main() {
    let txt = "ABABDABACDABABCABAB"
    let pat = "ABABCABAB"
    
    print("=== Knuth-Morris-Pratt (KMP) Search ===")
    print("Text: \"\(txt)\"")
    print("Pattern: \"\(pat)\"\n")
    
    runKMP(pat, txt)
    
    print("\nPress Enter to exit...")
    _ = readLine()
}

main()
