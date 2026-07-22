import Foundation

func printArray(_ arr: [Int]) {
    print("[", terminator: "")
    for i in 0..<arr.count {
        print(arr[i], terminator: "")
        if i < arr.count - 1 {
            print(", ", terminator: "")
        }
    }
    print("]")
}

func binarySearch(_ arr: [Int], _ low: Int, _ high: Int, _ target: Int) -> Int {
    if low > high {
        return -1
    }
    let mid = low + (high - low) / 2
    print("  Binary Search: Checking index \(mid) (value: \(arr[mid])) in range [\(low), \(high)]")
    if arr[mid] == target {
        return mid
    }
    if arr[mid] > target {
        return binarySearch(arr, low, mid - 1, target)
    }
    return binarySearch(arr, mid + 1, high, target)
}

func merge(_ arr: inout [Int], _ low: Int, _ mid: Int, _ high: Int) {
    let leftSize = mid - low + 1
    let rightSize = high - mid
    var leftArr = [Int](repeating: 0, count: leftSize)
    var rightArr = [Int](repeating: 0, count: rightSize)
    for i in 0..<leftSize {
        leftArr[i] = arr[low + i]
    }
    for j in 0..<rightSize {
        rightArr[j] = arr[mid + 1 + j]
    }
    var i = 0
    var j = 0
    var k = low
    while i < leftSize && j < rightSize {
        if leftArr[i] <= rightArr[j] {
            arr[k] = leftArr[i]
            i += 1
        } else {
            arr[k] = rightArr[j]
            j += 1
        }
        k += 1
    }
    while i < leftSize {
        arr[k] = leftArr[i]
        i += 1
        k += 1
    }
    while j < rightSize {
        arr[k] = rightArr[j]
        j += 1
        k += 1
    }
}

func mergeSort(_ arr: inout [Int], _ low: Int, _ high: Int) {
    if low < high {
        let mid = low + (high - low) / 2
        mergeSort(&arr, low, mid)
        mergeSort(&arr, mid + 1, high)
        merge(&arr, low, mid, high)
        print("  Merged range [\(low) to \(high)]: ", terminator: "")
        for x in low...high {
            print("\(arr[x]) ", terminator: "")
        }
        print()
    }
}

func partition(_ arr: inout [Int], _ low: Int, _ high: Int) -> Int {
    let pivot = arr[high]
    var i = low - 1
    for j in low..<high {
        if arr[j] < pivot {
            i += 1
            let temp = arr[i]
            arr[i] = arr[j]
            arr[j] = temp
        }
    }
    let temp = arr[i + 1]
    arr[i + 1] = arr[high]
    arr[high] = temp
    return i + 1
}

func quickSort(_ arr: inout [Int], _ low: Int, _ high: Int) {
    if low < high {
        let pi = partition(&arr, low, high)
        print("  Partition pivot chosen: \(arr[pi]). Array state: ", terminator: "")
        printArray(arr)
        quickSort(&arr, low, pi - 1)
        quickSort(&arr, pi + 1, high)
    }
}

func main() {
    var searchArr = [2, 5, 8, 12, 16, 23, 38, 56, 72, 91]
    let target = 23
    print("=== PART 1: Recursive Binary Search ===")
    let resultIndex = binarySearch(searchArr, 0, searchArr.count - 1, target)
    if resultIndex != -1 {
        print("Target found at index: \(resultIndex)\n")
    } else {
        print("Target not found.\n")
    }

    var mergeArr = [38, 27, 43, 3, 9, 82, 10]
    print("=== PART 2: Merge Sort ===")
    mergeSort(&mergeArr, 0, mergeArr.count - 1)
    print()

    var quickArr = [5, 2, 9, 1, 6]
    print("=== PART 3: Quick Sort ===")
    quickSort(&quickArr, 0, quickArr.count - 1)
    print()

    print("Press Enter to exit...", terminator: "")
    fflush(stdout)
    let _ = readLine()
}

main()
