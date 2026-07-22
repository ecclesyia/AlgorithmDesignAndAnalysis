use std::collections::VecDeque;
use std::io::{self, BufRead};

#[derive(Clone, Copy, Debug)]
struct Node {
    level: i32,
    profit: i32,
    weight: i32,
    bound: f64,
}

#[derive(Clone, Copy, Debug)]
struct Item {
    id: i32,
    weight: i32,
    value: i32,
}

fn calculate_bound(u: Node, n: usize, w_cap: i32, items: &[Item]) -> f64 {
    if u.weight >= w_cap {
        return 0.0;
    }

    let mut profit_bound = u.profit as f64;
    let mut j = (u.level + 1) as usize;
    let mut total_weight = u.weight;

    while j < n && total_weight + items[j].weight <= w_cap {
        total_weight += items[j].weight;
        profit_bound += items[j].value as f64;
        j += 1;
    }

    if j < n {
        profit_bound += (w_cap - total_weight) as f64 * (items[j].value as f64 / items[j].weight as f64);
    }

    profit_bound
}

fn solve_knapsack_bb(w_cap: i32, items: &mut [Item], n: usize) -> i32 {
    // Sort items by value-to-weight ratio descending
    items.sort_by(|a, b| {
        let r1 = a.value as f64 / a.weight as f64;
        let r2 = b.value as f64 / b.weight as f64;
        r2.partial_cmp(&r1).unwrap()
    });

    let mut q = VecDeque::new();

    let mut u = Node {
        level: -1,
        profit: 0,
        weight: 0,
        bound: 0.0,
    };
    u.bound = calculate_bound(u, n, w_cap, items);

    let mut max_profit = 0;
    q.push_back(u);

    println!("Branch and Bound Search Steps:");

    while let Some(curr_u) = q.pop_front() {
        let mut v = Node {
            level: 0,
            profit: 0,
            weight: 0,
            bound: 0.0,
        };

        if curr_u.level == -1 {
            v.level = 0;
        } else if curr_u.level == (n as i32) - 1 {
            continue; // Leaf node reached
        } else {
            v.level = curr_u.level + 1;
        }

        // --- BRANCH 1: Include next item ---
        let item_idx = v.level as usize;
        v.weight = curr_u.weight + items[item_idx].weight;
        v.profit = curr_u.profit + items[item_idx].value;

        if v.weight <= w_cap && v.profit > max_profit {
            max_profit = v.profit;
            println!("  Updated max profit to: {} (Level {}, Weight {})", max_profit, v.level, v.weight);
        }

        v.bound = calculate_bound(v, n, w_cap, items);

        if v.bound > max_profit as f64 {
            q.push_back(v);
            println!("    Branch WITH item {} enqueued. Bound = {:.2}", items[item_idx].id, v.bound);
        } else {
            println!("    Branch WITH item {} pruned. Bound ({:.2}) <= MaxProfit ({})", items[item_idx].id, v.bound, max_profit);
        }

        // --- BRANCH 2: Exclude next item ---
        let mut v_exclude = Node {
            level: v.level,
            profit: curr_u.profit,
            weight: curr_u.weight,
            bound: 0.0,
        };
        v_exclude.bound = calculate_bound(v_exclude, n, w_cap, items);

        if v_exclude.bound > max_profit as f64 {
            q.push_back(v_exclude);
            println!("    Branch WITHOUT item {} enqueued. Bound = {:.2}", items[item_idx].id, v_exclude.bound);
        } else {
            println!("    Branch WITHOUT item {} pruned. Bound ({:.2}) <= MaxProfit ({})", items[item_idx].id, v_exclude.bound, max_profit);
        }
    }

    max_profit
}

fn main() {
    let w_cap = 10;
    let mut items = [
        Item { id: 1, weight: 2, value: 40 },
        Item { id: 2, weight: 5, value: 30 },
        Item { id: 3, weight: 10, value: 50 },
        Item { id: 4, weight: 5, value: 10 },
    ];
    let n = items.len();

    println!("=== Branch and Bound: 0/1 Knapsack ===");
    println!("Capacity: {}\n", w_cap);

    let max_profit = solve_knapsack_bb(w_cap, &mut items, n);

    println!("\nMaximum Profit: {}", max_profit);

    println!();
    println!("Press Enter to exit...");
    let mut iterator = io::stdin().lock().lines();
    let _ = iterator.next();
}
