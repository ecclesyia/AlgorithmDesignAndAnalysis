import sys

def print_array(arr, size):
    print("[", end="")
    for i in range(size):
        print(arr[i], end="")
        if i < size - 1:
            print(", ", end="")
    print("]")

def binary_search(arr, low, high, target):
    if low > high:
        return -1
    mid = low + (high - low) // 2
    print(f"  Binary Search: Checking index {mid} (value: {arr[mid]}) in range [{low}, {high}]")
    if arr[mid] == target:
        return mid
    if arr[mid] > target:
        return binary_search(arr, low, mid - 1, target)
    else:
        return binary_search(arr, mid + 1, high, target)

def merge(arr, low, mid, high):
    left_size = mid - low + 1
    right_size = high - mid
    left_arr = arr[low : mid + 1]
    right_arr = arr[mid + 1 : high + 1]
    
    i = 0
    j = 0
    k = low
    while i < left_size and j < right_size:
        if left_arr[i] <= right_arr[j]:
            arr[k] = left_arr[i]
            i += 1
        else:
            arr[k] = right_arr[j]
            j += 1
        k += 1
    
    while i < left_size:
        arr[k] = left_arr[i]
        i += 1
        k += 1
        
    while j < right_size:
        arr[k] = right_arr[j]
        j += 1
        k += 1

def merge_sort(arr, low, high):
    if low < high:
        mid = low + (high - low) // 2
        merge_sort(arr, low, mid)
        merge_sort(arr, mid + 1, high)
        merge(arr, low, mid, high)
        print(f"  Merged range [{low} to {high}]: ", end="")
        for x in range(low, high + 1):
            print(f"{arr[x]} ", end="")
        print()

def partition(arr, low, high):
    pivot = arr[high]
    i = low - 1
    for j in range(low, high):
        if arr[j] < pivot:
            i += 1
            arr[i], arr[j] = arr[j], arr[i]
    arr[i + 1], arr[high] = arr[high], arr[i + 1]
    return i + 1

def quick_sort(arr, low, high):
    if low < high:
        pi = partition(arr, low, high)
        print(f"  Partition pivot chosen: {arr[pi]}. Array state: ", end="")
        print_array(arr, 5)
        quick_sort(arr, low, pi - 1)
        quick_sort(arr, pi + 1, high)

def main():
    search_arr = [2, 5, 8, 12, 16, 23, 38, 56, 72, 91]
    search_size = len(search_arr)
    target = 23
    print("=== PART 1: Recursive Binary Search ===")
    result_index = binary_search(search_arr, 0, search_size - 1, target)
    if result_index != -1:
        print(f"Target found at index: {result_index}\n")
    else:
        print("Target not found.\n")

    merge_arr = [38, 27, 43, 3, 9, 82, 10]
    merge_size = len(merge_arr)
    print("=== PART 2: Merge Sort ===")
    merge_sort(merge_arr, 0, merge_size - 1)
    print()

    quick_arr = [5, 2, 9, 1, 6]
    quick_size = len(quick_arr)
    print("=== PART 3: Quick Sort ===")
    quick_sort(quick_arr, 0, quick_size - 1)
    input("Press Enter to exit...")

if __name__ == "__main__":
    main()
