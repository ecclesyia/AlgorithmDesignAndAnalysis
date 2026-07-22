# Session 12: 0/1 Knapsack using Branch and Bound in Python

from collections import deque

class Node:
    def __init__(self, level=-1, profit=0, weight=0, bound=0.0):
        self.level = level
        self.profit = profit
        self.weight = weight
        self.bound = bound

class Item:
    def __init__(self, item_id, weight, value):
        self.id = item_id
        self.weight = weight
        self.value = value

def calculate_bound(u, n, W, items):
    if u.weight >= W:
        return 0.0
        
    profit_bound = float(u.profit)
    j = u.level + 1
    total_weight = u.weight
    
    while j < n and total_weight + items[j].weight <= W:
        total_weight += items[j].weight
        profit_bound += items[j].value
        j += 1
        
    if j < n:
        profit_bound += (W - total_weight) * (float(items[j].value) / items[j].weight)
        
    return profit_bound

def solve_knapsack_bb(W, items, n):
    # Sort items based on value/weight ratio in descending order
    items.sort(key=lambda item: float(item.value) / item.weight, reverse=True)
    
    queue = deque()
    u = Node(level=-1, profit=0, weight=0)
    u.bound = calculate_bound(u, n, W, items)
    max_profit = 0
    queue.append(u)
    
    while queue:
        u = queue.popleft()
        
        if u.level == -1:
            v_level = 0
        elif u.level == n - 1:
            continue
        else:
            v_level = u.level + 1
            
        # Branch with item
        v_with = Node(
            level=v_level,
            profit=u.profit + items[v_level].value,
            weight=u.weight + items[v_level].weight
        )
        if v_with.weight <= W and v_with.profit > max_profit:
            max_profit = v_with.profit
            
        v_with.bound = calculate_bound(v_with, n, W, items)
        if v_with.bound > max_profit:
            queue.append(v_with)
            
        # Branch without item
        v_without = Node(
            level=v_level,
            profit=u.profit,
            weight=u.weight
        )
        v_without.bound = calculate_bound(v_without, n, W, items)
        if v_without.bound > max_profit:
            queue.append(v_without)
            
    return max_profit

def main():
    items = [
        Item(1, 2, 40),
        Item(2, 5, 30),
        Item(3, 10, 50),
        Item(4, 5, 10)
    ]
    print(f"Max Profit: {solve_knapsack_bb(10, items, 4)}")

if __name__ == "__main__":
    main()
