#include <iostream>
#include <vector>

void printArray(int arr[], int size) {
    std::cout << "[";
    for (int i = 0; i < size; i++) {
        std::cout << arr[i];
        if (i < size - 1) std::cout << ", ";
    }
    std::cout << "]\n";
}

int binarySearch(int arr[], int low, int high, int target) {
    if (low > high) return -1;
    int mid = low + (high - low) / 2;
    std::cout << "  Binary Search: Checking index " << mid << " (value: " << arr[mid] << ") in range [" << low << ", " << high << "]\n";
    if (arr[mid] == target) return mid;
    if (arr[mid] > target) return binarySearch(arr, low, mid - 1, target);
    else return binarySearch(arr, mid + 1, high, target);
}

void merge(int arr[], int low, int mid, int high) {
    int leftSize = mid - low + 1;
    int rightSize = high - mid;
    std::vector<int> leftArr(leftSize);
    std::vector<int> rightArr(rightSize);
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

void mergeSort(int arr[], int low, int high) {
    if (low < high) {
        int mid = low + (high - low) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        merge(arr, low, mid, high);
        std::cout << "  Merged range [" << low << " to " << high << "]: ";
        for (int x = low; x <= high; x++) std::cout << arr[x] << " ";
        std::cout << "\n";
    }
}

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

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        std::cout << "  Partition pivot chosen: " << arr[pi] << ". Array state: ";
        printArray(arr, 5);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int searchArr[] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
    int searchSize = sizeof(searchArr) / sizeof(searchArr[0]);
    int target = 23;
    std::cout << "=== PART 1: Recursive Binary Search ===\n";
    int resultIndex = binarySearch(searchArr, 0, searchSize - 1, target);
    if (resultIndex != -1) std::cout << "Target found at index: " << resultIndex << "\n\n";
    else std::cout << "Target not found.\n\n";

    int mergeArr[] = {38, 27, 43, 3, 9, 82, 10};
    int mergeSize = sizeof(mergeArr) / sizeof(mergeArr[0]);
    std::cout << "=== PART 2: Merge Sort ===\n";
    mergeSort(mergeArr, 0, mergeSize - 1);
    std::cout << "\n";

    int quickArr[] = {5, 2, 9, 1, 6};
    int quickSize = sizeof(quickArr) / sizeof(quickArr[0]);
    std::cout << "=== PART 3: Quick Sort ===\n";
    quickSort(quickArr, 0, quickSize - 1);
    std::cout << "Press Enter to exit...";
    std::cin.get();
    return 0;
}
