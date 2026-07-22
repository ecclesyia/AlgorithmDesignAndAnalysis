use std::io::{self, Write};

#[derive(Clone, Copy)]
struct Activity {
    id: i32,
    start: i32,
    finish: i32,
}

fn select_activities(activities: &mut [Activity]) {
    activities.sort_by_key(|act| act.finish);
    println!("Sorted Activities by Finish Time:");
    for act in activities.iter() {
        println!("  Activity ID {}: [{}, {}]", act.id, act.start, act.finish);
    }

    println!("\nScheduling Decisions:");
    let mut selected_count = 0;
    let mut last_finish_time = activities[0].finish;
    println!("  Selected Activity ID {}: [{}, {}] (First to finish)", activities[0].id, activities[0].start, activities[0].finish);
    selected_count += 1;

    for i in 1..activities.len() {
        let act = activities[i];
        if act.start >= last_finish_time {
            println!("  Selected Activity ID {}: [{}, {}] (Starts after last finish {})", act.id, act.start, act.finish, last_finish_time);
            last_finish_time = act.finish;
            selected_count += 1;
        } else {
            println!("  Skipped Activity ID {}: [{}, {}] (Conflict)", act.id, act.start, act.finish);
        }
    }
    println!("\nTotal selected compatible activities: {}", selected_count);
}

fn main() {
    let mut activities = [
        Activity { id: 1, start: 5, finish: 9 },
        Activity { id: 2, start: 1, finish: 2 },
        Activity { id: 3, start: 3, finish: 4 },
        Activity { id: 4, start: 0, finish: 6 },
        Activity { id: 5, start: 5, finish: 7 },
        Activity { id: 6, start: 8, finish: 9 },
    ];
    select_activities(&mut activities);
    println!();
    
    print!("Press Enter to exit...");
    let _ = io::stdout().flush();
    let mut input = String::new();
    let _ = io::stdin().read_line(&mut input);
}
