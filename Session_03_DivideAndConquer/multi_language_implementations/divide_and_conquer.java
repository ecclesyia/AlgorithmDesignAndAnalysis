import java.util.Scanner;

public class divide_and_conquer {
    public static void printArray(int[] arr, int size) {
        System.out.print("[");
        for (int i = 0; i < size; i++) {
            System.out.print(arr[i]);
            if (i < size - 1) {
                System.out.print(", ");
            }
        }
        System.out.println("]");
    }

    public static int binarySearch(int[] arr, int low, int high, int target) {
        if (low > high) {
            return -1;
        }
        int mid = low + (high - low) / 2;
        System.out.println("  Binary Search: Checking index " + mid + " (value: " + arr[mid] + ") in range [" + low + ", " + high + "]");
        if (arr[mid] == target) {
            return mid;
        }
        if (arr[mid] > target) {
            return binarySearch(arr, low, mid - 1, target);
        } else {
            return binarySearch(arr, mid + 1, high, target);
        }
    }

    public static void merge(int[] arr, int low, int mid, int high) {
        int leftSize = mid - low + 1;
        int rightSize = high - mid;
        int[] leftArr = new int[leftSize];
        int[] rightArr = new int[rightSize];
        for (int i = 0; i < leftSize; i++) {
            leftArr[i] = arr[low + i];
        }
        for (int j = 0; j < rightSize; j++) {
            rightArr[j] = arr[mid + 1 + j];
        }
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

    public static void mergeSort(int[] arr, int low, int high) {
        if (low < high) {
            int mid = low + (high - low) / 2;
            mergeSort(arr, low, mid);
            mergeSort(arr, mid + 1, high);
            merge(arr, low, mid, high);
            System.out.print("  Merged range [" + low + " to " + high + "]: ");
            for (int x = low; x <= high; x++) {
                System.out.print(arr[x] + " ");
            }
            System.out.println();
        }
    }

    public static int partition(int[] arr, int low, int high) {
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

    public static void quickSort(int[] arr, int low, int high) {
        if (low < high) {
            int pi = partition(arr, low, high);
            System.out.print("  Partition pivot chosen: " + arr[pi] + ". Array state: ");
            printArray(arr, 5);
            quickSort(arr, low, pi - 1);
            quickSort(arr, pi + 1, high);
        }
    }

    public static void main(String[] args) {
        int[] searchArr = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
        int searchSize = searchArr.length;
        int target = 23;
        System.out.println("=== PART 1: Recursive Binary Search ===");
        int resultIndex = binarySearch(searchArr, 0, searchSize - 1, target);
        if (resultIndex != -1) {
            System.out.println("Target found at index: " + resultIndex + "\n");
        } else {
            System.out.println("Target not found.\n");
        }

        int[] mergeArr = {38, 27, 43, 3, 9, 82, 10};
        int mergeSize = mergeArr.length;
        System.out.println("=== PART 2: Merge Sort ===");
        mergeSort(mergeArr, 0, mergeSize - 1);
        System.out.println();

        int[] quickArr = {5, 2, 9, 1, 6};
        System.out.println("=== PART 3: Quick Sort ===");
        quickSort(quickArr, 0, quickArr.length - 1);
        System.out.print("Press Enter to exit...");
        Scanner scanner = new Scanner(System.in);
        scanner.nextLine();
        scanner.close();
    }
}
