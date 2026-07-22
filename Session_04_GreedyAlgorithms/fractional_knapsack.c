#include <stdio.h>
#include <stdlib.h>

/*
 * Session 04: Fractional Knapsack in C
 * Uses a greedy strategy by sorting items based on their value-to-weight ratio.
 */

typedef struct {
    int id;
    double value;
    double weight;
    double ratio;
} Item;

// Comparison function for qsort. Sorts items in descending order of ratio.
int compareItems(const void *a, const void *b) {
    Item *itemA = (Item *)a;
    Item *itemB = (Item *)b;
    if (itemB->ratio > itemA->ratio) return 1;
    if (itemB->ratio < itemA->ratio) return -1;
    return 0;
}

void solveFractionalKnapsack(Item items[], int size, double capacity) {
    // 1. Calculate ratio for each item
    for (int i = 0; i < size; i++) {
        items[i].ratio = items[i].value / items[i].weight;
    }

    // 2. Sort items by ratio descending
    qsort(items, size, sizeof(Item), compareItems);

    printf("Sorted Items by Value-to-Weight Ratio:\n");
    for (int i = 0; i < size; i++) {
        printf("  Item ID %d: Value = %.2f, Weight = %.2f, Ratio = %.4f\n", 
               items[i].id, items[i].value, items[i].weight, items[i].ratio);
    }
    printf("\n");

    double totalValue = 0.0;
    double remainingCapacity = capacity;

    printf("Knapsack Selection Steps:\n");
    for (int i = 0; i < size; i++) {
        if (remainingCapacity <= 0) break;

        if (items[i].weight <= remainingCapacity) {
            // Take the whole item
            remainingCapacity -= items[i].weight;
            totalValue += items[i].value;
            printf("  Took 100%% of Item ID %d (Weight: %.2f, Added Value: %.2f). Remaining Capacity: %.2f\n",
                   items[i].id, items[i].weight, items[i].value, remainingCapacity);
        } else {
            // Take a fraction of the item
            double fraction = remainingCapacity / items[i].weight;
            double addedValue = items[i].value * fraction;
            totalValue += addedValue;
            printf("  Took %.2f%% of Item ID %d (Weight: %.2f, Added Value: %.2f). Remaining Capacity: 0.00\n",
                   fraction * 100.0, items[i].id, remainingCapacity, addedValue);
            remainingCapacity = 0; // Knapsack is full
        }
    }

    printf("\nMaximum value possible in Knapsack of capacity %.2f is: %.2f\n", capacity, totalValue);
}

int main() {
    Item items[] = {
        {1, 60.0, 10.0, 0.0},
        {2, 100.0, 20.0, 0.0},
        {3, 120.0, 30.0, 0.0}
    };
    int size = sizeof(items) / sizeof(items[0]);
    double capacity = 50.0;

    printf("=== Greedy Optimization: Fractional Knapsack ===\n");
    printf("Total Knapsack Capacity: %.2f\n\n", capacity);

    solveFractionalKnapsack(items, size, capacity);

    printf("\nPress Enter to exit...");
    getchar();
    return 0;
}
