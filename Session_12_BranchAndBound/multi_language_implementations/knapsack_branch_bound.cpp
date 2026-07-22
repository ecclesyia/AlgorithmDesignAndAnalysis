// Session 12: 0/1 Knapsack using Branch and Bound in C++

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

struct Node {
    int level, profit, weight;
    double bound;
};

struct Item {
    int id, weight, value;
};

bool compareItems(const Item &a, const Item &b) {
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r2 < r1; // descending order
}

double calculateBound(Node u, int n, int W, const std::vector<Item> &items) {
    if (u.weight >= W) return 0.0;
    double profit_bound = u.profit;
    int j = u.level + 1;
    int total_weight = u.weight;
    while (j < n && total_weight + items[j].weight <= W) {
        total_weight += items[j].weight;
        profit_bound += items[j].value;
        j++;
    }
    if (j < n) {
        profit_bound += (W - total_weight) * ((double)items[j].value / items[j].weight);
    }
    return profit_bound;
}

int solveKnapsackBB(int W, std::vector<Item> &items, int n) {
    std::sort(items.begin(), items.end(), compareItems);
    std::queue<Node> q;
    Node u, v;
    u.level = -1; u.profit = 0; u.weight = 0;
    u.bound = calculateBound(u, n, W, items);
    int maxProfit = 0;
    q.push(u);

    while (!q.empty()) {
        u = q.front();
        q.pop();

        if (u.level == -1) v.level = 0;
        else if (u.level == n - 1) continue;
        else v.level = u.level + 1;

        // branch with item
        v.weight = u.weight + items[v.level].weight;
        v.profit = u.profit + items[v.level].value;
        if (v.weight <= W && v.profit > maxProfit) maxProfit = v.profit;
        v.bound = calculateBound(v, n, W, items);
        if (v.bound > maxProfit) q.push(v);

        // branch without item
        v.weight = u.weight; v.profit = u.profit;
        v.bound = calculateBound(v, n, W, items);
        if (v.bound > maxProfit) q.push(v);
    }
    return maxProfit;
}

int main() {
    std::vector<Item> items = {{1, 2, 40}, {2, 5, 30}, {3, 10, 50}, {4, 5, 10}};
    std::cout << "Max Profit: " << solveKnapsackBB(10, items, 4) << "\n";
    return 0;
}
