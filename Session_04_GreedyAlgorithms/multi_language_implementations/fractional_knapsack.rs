use std::io::{self, Write};

#[derive(Clone, Copy)]
struct Item {
    id: i32,
    value: f64,
    weight: f64,
    ratio: f64,
}

fn solve_fractional_knapsack(items: &mut [Item], capacity: f64) {
    for item in items.iter_mut() {
        item.ratio = item.value / item.weight;
    }

    items.sort_by(|a, b| b.ratio.partial_cmp(&a.ratio).unwrap());

    let mut total_value = 0.0;
    let mut remaining_capacity = capacity;

    for item in items.iter() {
        if remaining_capacity <= 0.0 {
            break;
        }
        if item.weight <= remaining_capacity {
            remaining_capacity -= item.weight;
            total_value += item.value;
        } else {
            let fraction = remaining_capacity / item.weight;
            total_value += item.value * fraction;
            remaining_capacity = 0.0;
        }
    }
    println!("Max Knapsack value: {:.2}", total_value);
}

fn main() {
    let mut items = [
        Item { id: 1, value: 60.0, weight: 10.0, ratio: 0.0 },
        Item { id: 2, value: 100.0, weight: 20.0, ratio: 0.0 },
        Item { id: 3, value: 120.0, weight: 30.0, ratio: 0.0 },
    ];
    solve_fractional_knapsack(&mut items, 50.0);
    println!();

    print!("Press Enter to exit...");
    let _ = io::stdout().flush();
    let mut input = String::new();
    let _ = io::stdin().read_line(&mut input);
}
