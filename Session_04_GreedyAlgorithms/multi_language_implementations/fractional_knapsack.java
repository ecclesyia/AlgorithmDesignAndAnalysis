import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

public class fractional_knapsack {
    public static class Item {
        int id;
        double value;
        double weight;
        double ratio;

        public Item(int id, double value, double weight) {
            this.id = id;
            this.value = value;
            this.weight = weight;
            this.ratio = 0.0;
        }
    }

    public static void solveFractionalKnapsack(Item[] items, double capacity) {
        for (int i = 0; i < items.length; i++) {
            items[i].ratio = items[i].value / items[i].weight;
        }

        Arrays.sort(items, new Comparator<Item>() {
            @Override
            public int compare(Item a, Item b) {
                return Double.compare(b.ratio, a.ratio);
            }
        });

        double totalValue = 0.0;
        double remainingCapacity = capacity;

        for (int i = 0; i < items.length; i++) {
            if (remainingCapacity <= 0) {
                break;
            }
            if (items[i].weight <= remainingCapacity) {
                remainingCapacity -= items[i].weight;
                totalValue += items[i].value;
            } else {
                double fraction = remainingCapacity / items[i].weight;
                totalValue += items[i].value * fraction;
                remainingCapacity = 0;
            }
        }
        System.out.printf("Max Knapsack value: %.2f\n", totalValue);
    }

    public static void main(String[] args) {
        Item[] items = {
            new Item(1, 60.0, 10.0),
            new Item(2, 100.0, 20.0),
            new Item(3, 120.0, 30.0)
        };
        solveFractionalKnapsack(items, 50.0);
        System.out.println();
        System.out.print("Press Enter to exit...");
        Scanner scanner = new Scanner(System.in);
        scanner.nextLine();
        scanner.close();
    }
}
