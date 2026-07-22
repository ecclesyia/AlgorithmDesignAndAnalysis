# Session 10: String Matching Algorithms

String matching is the problem of finding one or more occurrences of a pattern string $P$ inside a larger text string $T$. This session covers two efficient algorithms that improve on the naive search method: the Rabin-Karp algorithm (which uses rolling hashing) and the Knuth-Morris-Pratt (KMP) algorithm (which uses precomputed mismatch tables).

---

## Why is it Important to Learn This?

String searching is a core operation across all computing layers:
1. **Search Engines**: Crawlers search web page HTML documents for keywords and match text phrases.
2. **Text Editors**: The Ctrl + F find function utilizes highly optimized string matching algorithms to highlight matched words instantly in large documents.
3. **Intrusion Detection Systems**: Network firewalls scan incoming data packet payloads for known malicious signatures or virus bytes using multi-pattern matching.

---

## Academic Inspiration: CS50 and MIT

This session is inspired by:
* **Harvard's CS50 (Text Processing)**: Introducing character parsing and basic array scanning.
* **MIT's 6.006 (Lecture 8: String Matching)**: Explaining hash conflicts, analyzing the math of rolling hashes (calculating new hash values in $O(1)$ time by subtracting the oldest character and adding the newest), and proving KMP's linear $O(n + m)$ bound.

---

## Concepts Explained

### 1. The Naive Search Limitations

The naive approach slides the pattern over the text one character at a time, checking for matches. In the worst case (e.g., Text = "AAAAAAAB", Pattern = "AAB"), it backtracks repeatedly, resulting in $O(n \cdot m)$ time complexity.

### 2. Rabin-Karp Algorithm (Rolling Hash)

Rabin-Karp uses a hash function to filter out mismatch positions:
1. Compute the hash of the pattern of length $m$.
2. Compute the hash of the first substring of text of length $m$.
3. Slide the pattern window. Instead of computing the hash from scratch (which takes $O(m)$), calculate the next hash in $O(1)$ using the previous hash value:
   \[hash_{new} = d \cdot (hash_{old} - T[i] \cdot d^{m-1}) + T[i+m] \pmod q\]
4. If hashes match, verify character-by-character to handle potential **hash collisions**.

```text
Rabin-Karp sliding window:
Text:    [ A B C ] D E   (Hash = 234) -> Pattern Hash = 234? Match!
Text:    A [ B C D ] E   (Hash = 345) -> Pattern Hash = 234? No Match!
Text:    A B [ C D E ]   (Hash = 456) -> Pattern Hash = 234? No Match!
```

### 3. Knuth-Morris-Pratt (KMP) Algorithm

KMP avoids redundant backtracking by precomputing a prefix table (often called the **$\pi$-table** or **LPS table**: Longest Proper Prefix which is also a Suffix).
* When a mismatch occurs at $Pattern[j]$, we know that $Pattern[0..j-1]$ matched the text. The LPS table tells us the next index in the pattern to compare, allowing us to skip text indices that we know already match.
* **Time Complexity**: Guaranteed $O(n + m)$ runtime.

```text
LPS Table for Pattern "AABAACA":
Character:  A  A  B  A  A  C  A
Index:      0  1  2  3  4  5  6
LPS Value:  0  1  0  1  2  0  1
```

---

## Code Examples

Check the files in this directory:
* [rabin_karp.c](rabin_karp.c) - A C program implementing the Rabin-Karp rolling hash string search algorithm.
* [kmp.c](kmp.c) - A C program implementing the Knuth-Morris-Pratt (KMP) search using LPS table precomputation.
