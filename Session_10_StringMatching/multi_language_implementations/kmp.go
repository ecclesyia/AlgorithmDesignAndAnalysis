package main

import (
	"bufio"
	"fmt"
	"os"
)

func computeLPSArray(pat string, M int, lps []int) {
	lenPrev := 0
	lps[0] = 0
	i := 1

	for i < M {
		if pat[i] == pat[lenPrev] {
			lenPrev++
			lps[i] = lenPrev
			i++
		} else {
			if lenPrev != 0 {
				lenPrev = lps[lenPrev-1]
			} else {
				lps[i] = 0
				i++
			}
		}
	}
}

func runKMP(pat, txt string) {
	M := len(pat)
	N := len(txt)
	lps := make([]int, M)

	computeLPSArray(pat, M, lps)

	fmt.Printf("Precomputed LPS Table for pattern \"%s\":\n", pat)
	fmt.Print("  Char: ")
	for i := 0; i < M; i++ {
		fmt.Printf("%c ", pat[i])
	}
	fmt.Println()
	fmt.Print("  LPS:  ")
	for i := 0; i < M; i++ {
		fmt.Printf("%d ", lps[i])
	}
	fmt.Println()
	fmt.Println()

	i := 0
	j := 0

	fmt.Println("KMP Search steps:")
	for (N - i) >= (M - j) {
		if pat[j] == txt[i] {
			i++
			j++
		}

		if j == M {
			fmt.Printf("  Pattern found at index: %d\n", i-j)
			j = lps[j-1]
		} else if i < N && pat[j] != txt[i] {
			if j != 0 {
				fmt.Printf("  Mismatch at txt[%d] ('%c') and pat[%d] ('%c'). Sliding to pat[%d]\n",
					i, txt[i], j, pat[j], lps[j-1])
				j = lps[j-1]
			} else {
				i++
			}
		}
	}
}

func main() {
	txt := "ABABDABACDABABCABAB"
	pat := "ABABCABAB"

	fmt.Println("=== Knuth-Morris-Pratt (KMP) Search ===")
	fmt.Printf("Text: \"%s\"\n", txt)
	fmt.Printf("Pattern: \"%s\"\n", pat)
	fmt.Println()

	runKMP(pat, txt)

	fmt.Println()
	fmt.Print("Press Enter to exit...")
	bufio.NewReader(os.Stdin).ReadBytes('\n')
}
