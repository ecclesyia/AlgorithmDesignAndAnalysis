import sys

class Activity:
    def __init__(self, activity_id, start, finish):
        self.id = activity_id
        self.start = start
        self.finish = finish

def select_activities(activities):
    # Sort activities by finish time
    activities.sort(key=lambda x: x.finish)
    
    print("Sorted Activities by Finish Time:")
    for act in activities:
        print(f"  Activity ID {act.id}: [{act.start}, {act.finish}]")
    print("\nScheduling Decisions:")
    
    selected_count = 0
    last_finish_time = activities[0].finish
    print(f"  Selected Activity ID {activities[0].id}: [{activities[0].start}, {activities[0].finish}] (First to finish)")
    selected_count += 1
    
    for i in range(1, len(activities)):
        act = activities[i]
        if act.start >= last_finish_time:
            print(f"  Selected Activity ID {act.id}: [{act.start}, {act.finish}] (Starts after last finish {last_finish_time})")
            last_finish_time = act.finish
            selected_count += 1
        else:
            print(f"  Skipped Activity ID {act.id}: [{act.start}, {act.finish}] (Conflict)")
            
    print(f"\nTotal selected compatible activities: {selected_count}")

def main():
    activities = [
        Activity(1, 5, 9),
        Activity(2, 1, 2),
        Activity(3, 3, 4),
        Activity(4, 0, 6),
        Activity(5, 5, 7),
        Activity(6, 8, 9)
    ]
    select_activities(activities)
    print()
    input("Press Enter to exit...")

if __name__ == "__main__":
    main()
