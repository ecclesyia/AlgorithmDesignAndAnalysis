#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
 * Session 12: 0/1 Knapsack using Branch and Bound in C
 * Uses a FIFO Queue to perform Breadth-First search and evaluates bounds
 * to prune subtrees that cannot improve the maximum profit.
 * Time Complexity: O(2^n) worst-case, but significantly faster on average due to pruning
 * Space Complexity: O(2^n) to store queue nodes in worst-case
 */

typedef struct {
    int level;  // Level of node in decision tree (index of item)
    int profit; // Total profit of path from root to this node
    int weight; // Total weight of path from root to this node
    double bound; // Upper bound of maximum profit in subtree of this node
} Node;

typedef struct {
    int id;
    int weight;
    int value;
} Item;

// Structure for a simple Queue
typedef struct {
    Node *data;
    int front;
    int rear;
    int capacity;
} Queue;

Queue* createQueue(int capacity) {
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->capacity = capacity;
    q->front = 0;
    q->rear = 0;
    q->data = (Node *)malloc(capacity * sizeof(Node));
    return q;
}

void enqueue(Queue *q, Node node) {
    q->data[q->rear++] = node;
}

Node dequeue(Queue *q) {
    return q->data[q->front++];
}

bool isEmpty(Queue *q) {
    return q->front == q->rear;
}

void freeQueue(Queue *q) {
    free(q->data);
    free(q);
}

// Comparison function to sort items by value-to-weight ratio descending
int compareItems(const void *a, const void *b) {
    Item *itemA = (Item *)a;
    Item *itemB = (Item *)b;
    double r1 = (double)itemA->value / itemA->weight;
    double r2 = (double)itemB->value / itemB->weight;
    if (r2 > r1) return 1;
    if (r2 < r1) return -1;
    return 0;
}

// Calculates the upper bound of profit in subtree of node u
double calculateBound(Node u, int n, int W, Item items[]) {
    // If weight exceeds capacity, return 0 as bound
    if (u.weight >= W) {
        return 0;
    }

    double profit_bound = u.profit;
    int j = u.level + 1;
    int total_weight = u.weight;

    // Greedily include items in knapsack (like Fractional Knapsack)
    while (j < n && total_weight + items[j].weight <= W) {
        total_weight += items[j].weight;
        profit_bound += items[j].value;
        j++;
    }

    // If there are still items left, take a fraction of the next item
    if (j < n) {
        profit_bound += (W - total_weight) * ((double)items[j].value / items[j].weight);
    }

    return profit_bound;
}

int solveKnapsackBB(int W, Item items[], int n) {
    // Sort items by ratio descending
    qsort(items, n, sizeof(Item), compareItems);

    // Create queue for Breadth-First search
    Queue *q = createQueue(1000);

    Node u, v; // u is parent node, v is child node

    // Initialize root node
    u.level = -1;
    u.profit = 0;
    u.weight = 0;
    u.bound = calculateBound(u, n, W, items);

    int maxProfit = 0;
    enqueue(q, u);

    printf("Branch and Bound Search Steps:\n");

    while (!isEmpty(q)) {
        u = dequeue(q);

        // If it is starting node, level will be -1. Move to next item index
        if (u.level == -1) {
            v.level = 0;
        } else if (u.level == n - 1) {
            continue; // Leaf node reached
        } else {
            v.level = u.level + 1;
        }

        // --- BRANCH 1: Include next item ---
        v.weight = u.weight + items[v.level].weight;
        v.profit = u.profit + items[v.level].value;

        // If cumulative weight is less than W and profit is greater than maxProfit, update maxProfit
        if (v.weight <= W && v.profit > maxProfit) {
            maxProfit = v.profit;
            printf("  Updated max profit to: %d (Level %d, Weight %d)\n", maxProfit, v.level, v.weight);
        }

        v.bound = calculateBound(v, n, W, items);
        
        // If bound is greater than maxProfit, add node to queue for further exploration
        if (v.bound > maxProfit) {
            enqueue(q, v);
            printf("    Branch WITH item %d enqueued. Bound = %.2f\n", items[v.level].id, v.bound);
        } else {
            printf("    Branch WITH item %d pruned. Bound (%.2f) <= MaxProfit (%d)\n", items[v.level].id, v.bound, maxProfit);
        }

        // --- BRANCH 2: Exclude next item ---
        v.weight = u.weight;
        v.profit = u.profit;
        v.bound = calculateBound(v, n, W, items);

        if (v.bound > maxProfit) {
            enqueue(q, v);
            printf("    Branch WITHOUT item %d enqueued. Bound = %.2f\n", items[v.level].id, v.bound);
        } else {
            printf("    Branch WITHOUT item %d pruned. Bound (%.2f) <= MaxProfit (%d)\n", items[v.level].id, v.bound, maxProfit);
        }
    }

    freeQueue(q);
    return maxProfit;
}

int main() {
    int W = 10;
    Item items[] = {
        {1, 2, 40},
        {2, 5, 30},
        {3, 10, 50},
        {4, 5, 10}
    };
    int n = sizeof(items) / sizeof(items[0]);

    printf("=== Branch and Bound: 0/1 Knapsack ===\n");
    printf("Capacity: %d\n\n", W);

    int maxProfit = solveKnapsackBB(W, items, n);

    printf("\nMaximum Profit: %d\n", maxProfit);

    printf("\nPress Enter to exit...");
    getchar();
    return 0;
}
