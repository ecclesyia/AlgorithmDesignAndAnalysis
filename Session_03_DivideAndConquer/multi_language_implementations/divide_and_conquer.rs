use std::io::{self, Write};

fn print_array(arr: &[i32]) {
    print!("[");
    for i in 0..arr.len() {
        print!("{}", arr[i]);
        if i < arr.len() - 1 {
            print!(", ");
        }
    }
    println!("]");
}

fn binary_search(arr: &[i32], low: isize, high: isize, target: i32) -> isize {
    if low > high {
        return -1;
    }
    let mid = low + (high - low) / 2;
    println!("  Binary Search: Checking index {} (value: {}) in range [{}, {}]", mid, arr[mid as usize], low, high);
    if arr[mid as usize] == target {
        return mid;
    }
    if arr[mid as usize] > target {
        return binary_search(arr, low, mid - 1, target);
    }
    return binary_search(arr, mid + 1, high, target);
}

fn merge(arr: &mut [i32], low: usize, mid: usize, high: usize) {
    let left_size = mid - low + 1;
    let right_size = high - mid;
    let mut left_arr = vec![0; left_size];
    let mut right_arr = vec![0; right_size];
    for i in 0..left_size {
        left_arr[i] = arr[low + i];
    }
    for j in 0..right_size {
        right_arr[j] = arr[mid + 1 + j];
    }
    let mut i = 0;
    let mut j = 0;
    let mut k = low;
    while i < left_size && j < right_size {
        if left_arr[i] <= right_arr[j] {
            arr[k] = left_arr[i];
            i += 1;
        } else {
            arr[k] = right_arr[j];
            j += 1;
        }
        k += 1;
    }
    while i < left_size {
        arr[k] = left_arr[i];
        i += 1;
        k += 1;
    }
    while j < right_size {
        arr[k] = right_arr[j];
        j += 1;
        k += 1;
    }
}

fn merge_sort(arr: &mut [i32], low: usize, high: usize) {
    if low < high {
        let mid = low + (high - low) / 2;
        merge_sort(arr, low, mid);
        merge_sort(arr, mid + 1, high);
        merge(arr, low, mid, high);
        print!("  Merged range [{} to {}]: ", low, high);
        for x in low..=high {
            print!("{} ", arr[x]);
        }
        println!();
    }
}

fn partition(arr: &mut [i32], low: usize, high: usize) -> usize {
    let pivot = arr[high];
    let mut i = low as isize - 1;
    for j in low..high {
        if arr[j] < pivot {
            i += 1;
            arr.swap(i as usize, j);
        }
    }
    arr.swap((i + 1) as usize, high);
    (i + 1) as usize
}

fn quick_sort(arr: &mut [i32], low: usize, high: usize) {
    if low < high {
        let pi = partition(arr, low, high);
        print!("  Partition pivot chosen: {}. Array state: ", arr[pi]);
        print_array(arr);
        if pi > 0 {
            quick_sort(arr, low, pi - 1);
        }
        quick_sort(arr, pi + 1, high);
    }
}

fn main() {
    let mut search_arr = [2, 5, 8, 12, 16, 23, 38, 56, 72, 91];
    let target = 23;
    println!("=== PART 1: Recursive Binary Search ===");
    let result_index = binary_search(&mut search_arr, 0, (search_arr.len() - 1) as isize, target);
    if result_index != -1 {
        println!("Target found at index: {}\n", result_index);
    } else {
        println!("Target not found.\n");
    }

    let mut merge_arr = [38, 27, 43, 3, 9, 82, 10];
    println!("=== PART 2: Merge Sort ===");
    merge_sort(&mut merge_arr, 0, merge_arr.len() - 1);
    println!();

    let mut quick_arr = [5, 2, 9, 1, 6];
    println!("=== PART 3: Quick Sort ===");
    quick_sort(&mut quick_arr, 0, quick_arr.len() - 1);
    println!();

    print!("Press Enter to exit...");
    let _ = io::stdout().flush();
    let mut input = String::new();
    let _ = io::stdin().read_line(&mut input);
}
