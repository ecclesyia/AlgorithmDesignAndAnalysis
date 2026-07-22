package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

type Item struct {
	id     int
	value  float64
	weight float64
	ratio  float64
}

func solveFractionalKnapsack(items []Item, capacity float64) {
	for i := range items {
		items[i].ratio = items[i].value / items[i].weight
	}

	sort.Slice(items, func(i, j int) bool {
		return items[i].ratio > items[j].ratio
	})

	totalValue := 0.0
	remainingCapacity := capacity

	for i := 0; i < len(items); i++ {
		if remainingCapacity <= 0 {
			break
		}
		if items[i].weight <= remainingCapacity {
			remainingCapacity -= items[i].weight
			totalValue += items[i].value
		} else {
			fraction := remainingCapacity / items[i].weight
			totalValue += items[i].value * fraction
			remainingCapacity = 0
		}
	}
	fmt.Printf("Max Knapsack value: %.2f\n", totalValue)
}

func main() {
	items := []Item{
		{1, 60.0, 10.0, 0.0},
		{2, 100.0, 20.0, 0.0},
		{3, 120.0, 30.0, 0.0},
	}
	solveFractionalKnapsack(items, 50.0)
	fmt.Printf("\nPress Enter to exit...")
	bufio.NewReader(os.Stdin).ReadBytes('\n')
}
