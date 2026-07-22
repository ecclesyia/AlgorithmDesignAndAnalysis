const readline = require('readline');

const d = 256;
const q = 101;

function runRabinKarp(pat, txt) {
    const M = pat.length;
    const N = txt.length;
    let p = 0;
    let t = 0;
    let h = 1;

    for (let i = 0; i < M - 1; i++) {
        h = (h * d) % q;
    }

    for (let i = 0; i < M; i++) {
        p = (d * p + pat.charCodeAt(i)) % q;
        t = (d * t + txt.charCodeAt(i)) % q;
    }

    console.log("Rabin-Karp Search details:");
    console.log(`  Pattern hash: ${p}`);

    for (let i = 0; i <= N - M; i++) {
        if (p === t) {
            console.log(`  Hash match found at index ${i} (hash: ${t}). Checking characters...`);
            let j = 0;
            for (j = 0; j < M; j++) {
                if (txt[i + j] !== pat[j]) {
                    break;
                }
            }
            if (j === M) {
                console.log(`    Pattern found at index: ${i}`);
            }
        }

        if (i < N - M) {
            t = (d * (t - txt.charCodeAt(i) * h) + txt.charCodeAt(i + M)) % q;
            if (t < 0) {
                t += q;
            }
        }
    }
}

function main() {
    const txt = "GEEKS FOR GEEKS";
    const pat = "GEEK";

    console.log("=== Rabin-Karp String Search ===");
    console.log(`Text: "${txt}"`);
    console.log(`Pattern: "${pat}"\n`);

    runRabinKarp(pat, txt);

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
