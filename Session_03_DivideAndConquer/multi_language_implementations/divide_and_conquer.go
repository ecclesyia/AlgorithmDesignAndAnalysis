package main

import (
	"bufio"
	"fmt"
	"os"
)

func printArray(arr []int) {
	fmt.Printf("[")
	for i, val := range arr {
		fmt.Printf("%d", val)
		if i < len(arr)-1 {
			fmt.Printf(", ")
		}
	}
	fmt.Printf("]\n")
}

func binarySearch(arr []int, low int, high int, target int) int {
	if low > high {
		return -1
	}
	mid := low + (high-low)/2
	fmt.Printf("  Binary Search: Checking index %d (value: %d) in range [%d, %d]\n", mid, arr[mid], low, high)
	if arr[mid] == target {
		return mid
	}
	if arr[mid] > target {
		return binarySearch(arr, low, mid-1, target)
	}
	return binarySearch(arr, mid+1, high, target)
}

func merge(arr []int, low int, mid int, high int) {
	leftSize := mid - low + 1
	rightSize := high - mid
	leftArr := make([]int, leftSize)
	rightArr := make([]int, rightSize)
	for i := 0; i < leftSize; i++ {
		leftArr[i] = arr[low+i]
	}
	for j := 0; j < rightSize; j++ {
		rightArr[j] = arr[mid+1+j]
	}
	i, j, k := 0, 0, low
	for i < leftSize && j < rightSize {
		if leftArr[i] <= rightArr[j] {
			arr[k] = leftArr[i]
			i++
		} else {
			arr[k] = rightArr[j]
			j++
		}
		k++
	}
	for i < leftSize {
		arr[k] = leftArr[i]
		i++
		k++
	}
	for j < rightSize {
		arr[k] = rightArr[j]
		j++
		k++
	}
}

func mergeSort(arr []int, low int, high int) {
	if low < high {
		mid := low + (high-low)/2
		mergeSort(arr, low, mid)
		mergeSort(arr, mid+1, high)
		merge(arr, low, mid, high)
		fmt.Printf("  Merged range [%d to %d]: ", low, high)
		for x := low; x <= high; x++ {
			fmt.Printf("%d ", arr[x])
		}
		fmt.Printf("\n")
	}
}

func partition(arr []int, low int, high int) int {
	pivot := arr[high]
	i := low - 1
	for j := low; j < high; j++ {
		if arr[j] < pivot {
			i++
			arr[i], arr[j] = arr[j], arr[i]
		}
	}
	arr[i+1], arr[high] = arr[high], arr[i+1]
	return i + 1
}

func quickSort(arr []int, low int, high int) {
	if low < high {
		pi := partition(arr, low, high)
		fmt.Printf("  Partition pivot chosen: %d. Array state: ", arr[pi])
		printArray(arr)
		quickSort(arr, low, pi-1)
		quickSort(arr, pi+1, high)
	}
}

func main() {
	searchArr := []int{2, 5, 8, 12, 16, 23, 38, 56, 72, 91}
	target := 23
	fmt.Printf("=== PART 1: Recursive Binary Search ===\n")
	resultIndex := binarySearch(searchArr, 0, len(searchArr)-1, target)
	if resultIndex != -1 {
		fmt.Printf("Target found at index: %d\n\n", resultIndex)
	} else {
		fmt.Printf("Target not found.\n\n")
	}

	mergeArr := []int{38, 27, 43, 3, 9, 82, 10}
	fmt.Printf("=== PART 2: Merge Sort ===\n")
	mergeSort(mergeArr, 0, len(mergeArr)-1)
	fmt.Println()

	quickArr := []int{5, 2, 9, 1, 6}
	fmt.Printf("=== PART 3: Quick Sort ===\n")
	quickSort(quickArr, 0, len(quickArr)-1)
	fmt.Println()

	fmt.Printf("Press Enter to exit...")
	bufio.NewReader(os.Stdin).ReadBytes('\n')
}
