import java.util.Scanner

fun printArray(arr: IntArray) {
    print("[")
    for (i in arr.indices) {
        print(arr[i])
        if (i < arr.size - 1) {
            print(", ")
        }
    }
    println("]")
}

fun binarySearch(arr: IntArray, low: Int, high: Int, target: Int): Int {
    if (low > high) return -1
    val mid = low + (high - low) / 2
    println("  Binary Search: Checking index $mid (value: ${arr[mid]}) in range [$low, $high]")
    if (arr[mid] == target) return mid
    return if (arr[mid] > target) {
        binarySearch(arr, low, mid - 1, target)
    } else {
        binarySearch(arr, mid + 1, high, target)
    }
}

fun merge(arr: IntArray, low: Int, mid: Int, high: Int) {
    val leftSize = mid - low + 1
    val rightSize = high - mid
    val leftArr = IntArray(leftSize)
    val rightArr = IntArray(rightSize)
    for (i in 0 until leftSize) {
        leftArr[i] = arr[low + i]
    }
    for (j in 0 until rightSize) {
        rightArr[j] = arr[mid + 1 + j]
    }
    var i = 0
    var j = 0
    var k = low
    while (i < leftSize && j < rightSize) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i]
            i++
        } else {
            arr[k] = rightArr[j]
            j++
        }
        k++
    }
    while (i < leftSize) {
        arr[k] = leftArr[i]
        i++
        k++
    }
    while (j < rightSize) {
        arr[k] = rightArr[j]
        j++
        k++
    }
}

fun mergeSort(arr: IntArray, low: Int, high: Int) {
    if (low < high) {
        val mid = low + (high - low) / 2
        mergeSort(arr, low, mid)
        mergeSort(arr, mid + 1, high)
        merge(arr, low, mid, high)
        print("  Merged range [$low to $high]: ")
        for (x in low..high) {
            print("${arr[x]} ")
        }
        println()
    }
}

fun partition(arr: IntArray, low: Int, high: Int): Int {
    val pivot = arr[high]
    var i = low - 1
    for (j in low until high) {
        if (arr[j] < pivot) {
            i++
            val temp = arr[i]
            arr[i] = arr[j]
            arr[j] = temp
        }
    }
    val temp = arr[i + 1]
    arr[i + 1] = arr[high]
    arr[high] = temp
    return i + 1
}

fun quickSort(arr: IntArray, low: Int, high: Int) {
    if (low < high) {
        val pi = partition(arr, low, high)
        print("  Partition pivot chosen: ${arr[pi]}. Array state: ")
        printArray(arr)
        quickSort(arr, low, pi - 1)
        quickSort(arr, pi + 1, high)
    }
}

fun main() {
    val searchArr = intArrayOf(2, 5, 8, 12, 16, 23, 38, 56, 72, 91)
    val target = 23
    println("=== PART 1: Recursive Binary Search ===")
    val resultIndex = binarySearch(searchArr, 0, searchArr.size - 1, target)
    if (resultIndex != -1) {
        println("Target found at index: $resultIndex\n")
    } else {
        println("Target not found.\n")
    }

    val mergeArr = intArrayOf(38, 27, 43, 3, 9, 82, 10)
    println("=== PART 2: Merge Sort ===")
    mergeSort(mergeArr, 0, mergeArr.size - 1)
    println()

    val quickArr = intArrayOf(5, 2, 9, 1, 6)
    println("=== PART 3: Quick Sort ===")
    quickSort(quickArr, 0, quickArr.size - 1)
    println()

    print("Press Enter to exit...")
    Scanner(System.`in`).nextLine()
}
