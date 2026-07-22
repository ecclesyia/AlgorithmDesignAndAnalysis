const readline = require('readline');

function printArray(arr) {
    console.log("[" + arr.join(", ") + "]");
}

function binarySearch(arr, low, high, target) {
    if (low > high) return -1;
    const mid = low + Math.floor((high - low) / 2);
    console.log(`  Binary Search: Checking index ${mid} (value: ${arr[mid]}) in range [${low}, ${high}]`);
    if (arr[mid] === target) return mid;
    if (arr[mid] > target) return binarySearch(arr, low, mid - 1, target);
    return binarySearch(arr, mid + 1, high, target);
}

function merge(arr, low, mid, high) {
    const leftSize = mid - low + 1;
    const rightSize = high - mid;
    const leftArr = new Array(leftSize);
    const rightArr = new Array(rightSize);
    for (let i = 0; i < leftSize; i++) leftArr[i] = arr[low + i];
    for (let j = 0; j < rightSize; j++) rightArr[j] = arr[mid + 1 + j];
    let i = 0, j = 0, k = low;
    while (i < leftSize && j < rightSize) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }
    while (i < leftSize) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }
    while (j < rightSize) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

function mergeSort(arr, low, high) {
    if (low < high) {
        const mid = low + Math.floor((high - low) / 2);
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        merge(arr, low, mid, high);
        let mergedStr = "";
        for (let x = low; x <= high; x++) {
            mergedStr += arr[x] + " ";
        }
        console.log(`  Merged range [${low} to ${high}]: ${mergedStr}`);
    }
}

function partition(arr, low, high) {
    const pivot = arr[high];
    let i = low - 1;
    for (let j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            const temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    const temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return i + 1;
}

function quickSort(arr, low, high) {
    if (low < high) {
        const pi = partition(arr, low, high);
        process.stdout.write(`  Partition pivot chosen: ${arr[pi]}. Array state: `);
        printArray(arr);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

function main() {
    const searchArr = [2, 5, 8, 12, 16, 23, 38, 56, 72, 91];
    const target = 23;
    console.log("=== PART 1: Recursive Binary Search ===");
    const resultIndex = binarySearch(searchArr, 0, searchArr.length - 1, target);
    if (resultIndex !== -1) console.log(`Target found at index: ${resultIndex}\n`);
    else console.log("Target not found.\n");

    const mergeArr = [38, 27, 43, 3, 9, 82, 10];
    console.log("=== PART 2: Merge Sort ===");
    mergeSort(mergeArr, 0, mergeArr.length - 1);
    console.log();

    const quickArr = [5, 2, 9, 1, 6];
    console.log("=== PART 3: Quick Sort ===");
    quickSort(quickArr, 0, quickArr.length - 1);
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
