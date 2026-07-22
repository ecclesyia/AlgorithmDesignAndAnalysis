// Session 12: 0/1 Knapsack using Branch and Bound in Java

import java.util.Arrays;
import java.util.Comparator;
import java.util.LinkedList;
import java.util.Queue;

public class knapsack_branch_bound {
    static class Node {
        int level;
        int profit;
        int weight;
        double bound;

        Node() {
            this.level = -1;
            this.profit = 0;
            this.weight = 0;
            this.bound = 0.0;
        }

        Node(int level, int profit, int weight) {
            this.level = level;
            this.profit = profit;
            this.weight = weight;
            this.bound = 0.0;
        }
    }

    static class Item {
        int id;
        int weight;
        int value;

        Item(int id, int weight, int value) {
            this.id = id;
            this.weight = weight;
            this.value = value;
        }
    }

    public static double calculateBound(Node u, int n, int W, Item[] items) {
        if (u.weight >= W) {
            return 0.0;
        }
        double profitBound = u.profit;
        int j = u.level + 1;
        int totalWeight = u.weight;

        while (j < n && totalWeight + items[j].weight <= W) {
            totalWeight += items[j].weight;
            profitBound += items[j].value;
            j++;
        }

        if (j < n) {
            profitBound += (W - totalWeight) * ((double) items[j].value / items[j].weight);
        }

        return profitBound;
    }

    public static int solveKnapsackBB(int W, Item[] items, int n) {
        Arrays.sort(items, new Comparator<Item>() {
            @Override
            public int compare(Item a, Item b) {
                double r1 = (double) a.value / a.weight;
                double r2 = (double) b.value / b.weight;
                return Double.compare(r2, r1);
            }
        });

        Queue<Node> q = new LinkedList<>();
        Node u = new Node(-1, 0, 0);
        u.bound = calculateBound(u, n, W, items);
        int maxProfit = 0;
        q.add(u);

        while (!q.isEmpty()) {
            u = q.poll();

            int vLevel;
            if (u.level == -1) {
                vLevel = 0;
            } else if (u.level == n - 1) {
                continue;
            } else {
                vLevel = u.level + 1;
            }

            // Branch with item
            Node vWith = new Node(vLevel, u.profit + items[vLevel].value, u.weight + items[vLevel].weight);
            if (vWith.weight <= W && vWith.profit > maxProfit) {
                maxProfit = vWith.profit;
            }
            vWith.bound = calculateBound(vWith, n, W, items);
            if (vWith.bound > maxProfit) {
                q.add(vWith);
            }

            // Branch without item
            Node vWithout = new Node(vLevel, u.profit, u.weight);
            vWithout.bound = calculateBound(vWithout, n, W, items);
            if (vWithout.bound > maxProfit) {
                q.add(vWithout);
            }
        }

        return maxProfit;
    }

    public static void main(String[] args) {
        Item[] items = {
            new Item(1, 2, 40),
            new Item(2, 5, 30),
            new Item(3, 10, 50),
            new Item(4, 5, 10)
        };
        System.out.println("Max Profit: " + solveKnapsackBB(10, items, 4));
    }
}
