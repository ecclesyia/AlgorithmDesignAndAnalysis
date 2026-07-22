const readline = require('readline');

function computeLPSArray(pat, M, lps) {
    let lenPrev = 0;
    lps[0] = 0;
    let i = 1;

    while (i < M) {
        if (pat[i] === pat[lenPrev]) {
            lenPrev++;
            lps[i] = lenPrev;
            i++;
        } else {
            if (lenPrev !== 0) {
                lenPrev = lps[lenPrev - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

function runKMP(pat, txt) {
    const M = pat.length;
    const N = txt.length;
    const lps = Array(M).fill(0);

    computeLPSArray(pat, M, lps);

    console.log(`Precomputed LPS Table for pattern "${pat}":`);
    let charsRow = "  Char: ";
    for (let idx = 0; idx < M; idx++) {
        charsRow += pat[idx] + " ";
    }
    console.log(charsRow);

    let lpsRow = "  LPS:  ";
    for (let idx = 0; idx < M; idx++) {
        lpsRow += lps[idx] + " ";
    }
    console.log(lpsRow);
    console.log();

    let i = 0;
    let j = 0;

    console.log("KMP Search steps:");
    while ((N - i) >= (M - j)) {
        if (pat[j] === txt[i]) {
            i++;
            j++;
        }

        if (j === M) {
            console.log(`  Pattern found at index: ${i - j}`);
            j = lps[j - 1];
        } else if (i < N && pat[j] !== txt[i]) {
            if (j !== 0) {
                console.log(`  Mismatch at txt[${i}] ('${txt[i]}') and pat[${j}] ('${pat[j]}'). Sliding to pat[${lps[j - 1]}]`);
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }
}

function main() {
    const txt = "ABABDABACDABABCABAB";
    const pat = "ABABCABAB";

    console.log("=== Knuth-Morris-Pratt (KMP) Search ===");
    console.log(`Text: "${txt}"`);
    console.log(`Pattern: "${pat}"\n`);

    runKMP(pat, txt);

    console.log();
    const rl = readline.createInterface({
        input: process.stdin,
        output: process.stdout
    });
    rl.question("Press Enter to exit...", () => {
        rl.close();
    });
}

main();
