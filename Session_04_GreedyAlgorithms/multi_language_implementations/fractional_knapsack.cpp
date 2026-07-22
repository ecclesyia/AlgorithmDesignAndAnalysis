#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

struct Item {
    int id;
    double value;
    double weight;
    double ratio;
};

bool compareItems(const Item &a, const Item &b) {
    return (a.ratio > b.ratio);
}

void solveFractionalKnapsack(std::vector<Item> &items, double capacity) {
    for (size_t i = 0; i < items.size(); i++) {
        items[i].ratio = items[i].value / items[i].weight;
    }
    std::sort(items.begin(), items.end(), compareItems);
    double totalValue = 0.0;
    double remainingCapacity = capacity;
    for (size_t i = 0; i < items.size(); i++) {
        if (remainingCapacity <= 0) break;
        if (items[i].weight <= remainingCapacity) {
            remainingCapacity -= items[i].weight;
            totalValue += items[i].value;
        } else {
            double fraction = remainingCapacity / items[i].weight;
            totalValue += items[i].value * fraction;
            remainingCapacity = 0;
        }
    }
    std::cout << "Max Knapsack value: " << std::fixed << std::setprecision(2) << totalValue << "\n";
}

int main() {
    std::vector<Item> items = {{1, 60.0, 10.0, 0.0}, {2, 100.0, 20.0, 0.0}, {3, 120.0, 30.0, 0.0}};
    solveFractionalKnapsack(items, 50.0);
    std::cout << "\nPress Enter to exit...";
    std::cin.get();
    return 0;
}
