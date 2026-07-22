package main

import (
	"bufio"
	"fmt"
	"os"
)

const d = 256
const q = 101

func runRabinKarp(pat, txt string) {
	M := len(pat)
	N := len(txt)
	p := 0
	t := 0
	h := 1

	for i := 0; i < M-1; i++ {
		h = (h * d) % q
	}

	for i := 0; i < M; i++ {
		p = (d*p + int(pat[i])) % q
		t = (d*t + int(txt[i])) % q
	}

	fmt.Println("Rabin-Karp Search details:")
	fmt.Printf("  Pattern hash: %d\n", p)

	for i := 0; i <= N-M; i++ {
		if p == t {
			fmt.Printf("  Hash match found at index %d (hash: %d). Checking characters...\n", i, t)
			j := 0
			for j = 0; j < M; j++ {
				if txt[i+j] != pat[j] {
					break
				}
			}
			if j == M {
				fmt.Printf("    Pattern found at index: %d\n", i)
			}
		}

		if i < N-M {
			t = (d*(t-int(txt[i])*h) + int(txt[i+M])) % q
			if t < 0 {
				t = t + q
			}
		}
	}
}

func main() {
	txt := "GEEKS FOR GEEKS"
	pat := "GEEK"

	fmt.Println("=== Rabin-Karp String Search ===")
	fmt.Printf("Text: \"%s\"\n", txt)
	fmt.Printf("Pattern: \"%s\"\n", pat)
	fmt.Println()

	runRabinKarp(pat, txt)

	fmt.Println()
	fmt.Print("Press Enter to exit...")
	bufio.NewReader(os.Stdin).ReadBytes('\n')
}
