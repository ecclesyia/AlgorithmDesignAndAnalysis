import Foundation

let d = 256
let q = 101

func runRabinKarp(_ pat: String, _ txt: String) {
    let patChars = Array(pat.utf8).map { Int($0) }
    let txtChars = Array(txt.utf8).map { Int($0) }
    let M = patChars.count
    let N = txtChars.count
    var p = 0
    var t = 0
    var h = 1
    
    for _ in 0..<M - 1 {
        h = (h * d) % q
    }
    
    for i in 0..<M {
        p = (d * p + patChars[i]) % q
        t = (d * t + txtChars[i]) % q
    }
    
    print("Rabin-Karp Search details:")
    print("  Pattern hash: \(p)")
    
    for i in 0...N - M {
        if p == t {
            print("  Hash match found at index \(i) (hash: \(t)). Checking characters...")
            var j = 0
            while j < M {
                if txtChars[i + j] != patChars[j] {
                    break
                }
                j += 1
            }
            if j == M {
                print("    Pattern found at index: \(i)")
            }
        }
        
        if i < N - M {
            t = (d * (t - txtChars[i] * h) + txtChars[i + M]) % q
            if t < 0 {
                t += q
            }
        }
    }
}

func main() {
    let txt = "GEEKS FOR GEEKS"
    let pat = "GEEK"
    
    print("=== Rabin-Karp String Search ===")
    print("Text: \"\(txt)\"")
    print("Pattern: \"\(pat)\"\n")
    
    runRabinKarp(pat, txt)
    
    print("\nPress Enter to exit...")
    _ = readLine()
}

main()
