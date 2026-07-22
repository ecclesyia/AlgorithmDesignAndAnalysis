#include <stdio.h>
#include <stdlib.h>

/*
 * Session 03: Divide and Conquer in C
 * Contains implementations of:
 * 1. Binary Search (Recursive)
 * 2. Merge Sort (Recursive with trace)
 * 3. Quick Sort (Lomuto Partitioning with trace)
 */

// Helper function to print an array
void printArray(int arr[], int size) {
    printf("[");
    for (int i = 0; i < size; i++) {
        printf("%d", arr[i]);
        if (i < size - 1) printf(", ");
    }
    printf("]\n");
}

// Recursive Binary Search
// Time complexity: O(log n)
// Space complexity: O(log n) stack space
int binarySearch(int arr[], int low, int high, int target) {
    if (low > high) {
        return -1; // Base case: Target not found
    }

    int mid = low + (high - low) / 2;
    printf("  Binary Search: Checking index %d (value: %d) in range [%d, %d]\n", mid, arr[mid], low, high);

    if (arr[mid] == target) {
        return mid; // Target found
    }

    if (arr[mid] > target) {
        return binarySearch(arr, low, mid - 1, target); // Search left half
    } else {
        return binarySearch(arr, mid + 1, high, target); // Search right half
    }
}

// Merge helper function for Merge Sort
// Combines two sorted sub-arrays: arr[low..mid] and arr[mid+1..high]
void merge(int arr[], int low, int mid, int high) {
    int leftSize = mid - low + 1;
    int rightSize = high - mid;

    // Temporary arrays
    int *leftArr = (int *)malloc(leftSize * sizeof(int));
    int *rightArr = (int *)malloc(rightSize * sizeof(int));

    for (int i = 0; i < leftSize; i++) leftArr[i] = arr[low + i];
    for (int j = 0; j < rightSize; j++) rightArr[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = low;
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

    // Copy remaining elements
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

    free(leftArr);
    free(rightArr);
}

// Merge Sort
// Time complexity: O(n log n)
// Space complexity: O(n) temporary buffer space
void mergeSort(int arr[], int low, int high) {
    if (low < high) {
        int mid = low + (high - low) / 2;

        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);

        merge(arr, low, mid, high);
        
        printf("  Merged range [%d to %d]: ", low, high);
        for (int x = low; x <= high; x++) {
            printf("%d ", arr[x]);
        }
        printf("\n");
    }
}

// Lomuto Partitioning for Quick Sort
// Uses the last element as the pivot
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return i + 1;
}

// Quick Sort
// Time complexity: O(n log n) average, O(n^2) worst-case
// Space complexity: O(log n) stack space
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        
        printf("  Partition pivot chosen: %d. Array state: ", arr[pi]);
        printArray(arr, 5); // Assuming size 5 for simple printing here

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    // 1. Binary Search Demonstration
    int searchArr[] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
    int searchSize = sizeof(searchArr) / sizeof(searchArr[0]);
    int target = 23;

    printf("=== PART 1: Recursive Binary Search ===\n");
    printf("Searching for target %d in sorted array:\n", target);
    printArray(searchArr, searchSize);
    int resultIndex = binarySearch(searchArr, 0, searchSize - 1, target);
    if (resultIndex != -1) {
        printf("Target found at index: %d\n\n", resultIndex);
    } else {
        printf("Target not found.\n\n");
    }

    printf("--------------------------------------------------\n\n");

    // 2. Merge Sort Demonstration
    int mergeArr[] = {38, 27, 43, 3, 9, 82, 10};
    int mergeSize = sizeof(mergeArr) / sizeof(mergeArr[0]);

    printf("=== PART 2: Merge Sort (Divide & Conquer) ===\n");
    printf("Unsorted array:\n");
    printArray(mergeArr, mergeSize);
    mergeSort(mergeArr, 0, mergeSize - 1);
    printf("Sorted array:\n");
    printArray(mergeArr, mergeSize);
    printf("\n");

    printf("--------------------------------------------------\n\n");

    // 3. Quick Sort Demonstration
    int quickArr[] = {5, 2, 9, 1, 6};
    int quickSize = sizeof(quickArr) / sizeof(quickArr[0]);

    printf("=== PART 3: Quick Sort (Divide & Conquer) ===\n");
    printf("Unsorted array:\n");
    printArray(quickArr, quickSize);
    quickSort(quickArr, 0, quickSize - 1);
    printf("Sorted array:\n");
    printArray(quickArr, quickSize);
    printf("\n");

    printf("Press Enter to exit...");
    getchar();
    return 0;
}
