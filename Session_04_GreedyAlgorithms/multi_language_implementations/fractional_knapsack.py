import sys

class Item:
    def __init__(self, item_id, value, weight):
        self.id = item_id
        self.value = value
        self.weight = weight
        self.ratio = 0.0

def solve_fractional_knapsack(items, capacity):
    for item in items:
        item.ratio = item.value / item.weight
        
    # Sort items by value/weight ratio descending
    items.sort(key=lambda x: x.ratio, reverse=True)
    
    total_value = 0.0
    remaining_capacity = capacity
    
    for item in items:
        if remaining_capacity <= 0:
            break
        if item.weight <= remaining_capacity:
            remaining_capacity -= item.weight
            total_value += item.value
        else:
            fraction = remaining_capacity / item.weight
            total_value += item.value * fraction
            remaining_capacity = 0
            
    print(f"Max Knapsack value: {total_value:.2f}")

def main():
    items = [
        Item(1, 60.0, 10.0),
        Item(2, 100.0, 20.0),
        Item(3, 120.0, 30.0)
    ]
    solve_fractional_knapsack(items, 50.0)
    print()
    input("Press Enter to exit...")

if __name__ == "__main__":
    main()
