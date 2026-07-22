package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

type Node struct {
	level  int
	profit int
	weight int
	bound  float64
}

type Item struct {
	id     int
	weight int
	value  int
}

func calculateBound(u Node, n, W int, items []Item) float64 {
	if u.weight >= W {
		return 0
	}

	profit_bound := float64(u.profit)
	j := u.level + 1
	total_weight := u.weight

	for j < n && total_weight+items[j].weight <= W {
		total_weight += items[j].weight
		profit_bound += float64(items[j].value)
		j++
	}

	if j < n {
		profit_bound += float64(W-total_weight) * (float64(items[j].value) / float64(items[j].weight))
	}

	return profit_bound
}

func solveKnapsackBB(W int, items []Item, n int) int {
	// Sort items by ratio descending
	sort.Slice(items, func(i, j int) bool {
		r1 := float64(items[i].value) / float64(items[i].weight)
		r2 := float64(items[j].value) / float64(items[j].weight)
		return r1 > r2
	})

	var q []Node

	var u Node
	u.level = -1
	u.profit = 0
	u.weight = 0
	u.bound = calculateBound(u, n, W, items)

	maxProfit := 0
	q = append(q, u)

	fmt.Println("Branch and Bound Search Steps:")

	for len(q) > 0 {
		u = q[0]
		q = q[1:]

		var v Node
		if u.level == -1 {
			v.level = 0
		} else if u.level == n-1 {
			continue
		} else {
			v.level = u.level + 1
		}

		// --- BRANCH 1: Include next item ---
		v.weight = u.weight + items[v.level].weight
		v.profit = u.profit + items[v.level].value

		if v.weight <= W && v.profit > maxProfit {
			maxProfit = v.profit
			fmt.Printf("  Updated max profit to: %d (Level %d, Weight %d)\n", maxProfit, v.level, v.weight)
		}

		v.bound = calculateBound(v, n, W, items)

		if v.bound > float64(maxProfit) {
			q = append(q, v)
			fmt.Printf("    Branch WITH item %d enqueued. Bound = %.2f\n", items[v.level].id, v.bound)
		} else {
			fmt.Printf("    Branch WITH item %d pruned. Bound (%.2f) <= MaxProfit (%d)\n", items[v.level].id, v.bound, maxProfit)
		}

		// --- BRANCH 2: Exclude next item ---
		v.weight = u.weight
		v.profit = u.profit
		v.bound = calculateBound(v, n, W, items)

		if v.bound > float64(maxProfit) {
			q = append(q, v)
			fmt.Printf("    Branch WITHOUT item %d enqueued. Bound = %.2f\n", items[v.level].id, v.bound)
		} else {
			fmt.Printf("    Branch WITHOUT item %d pruned. Bound (%.2f) <= MaxProfit (%d)\n", items[v.level].id, v.bound, maxProfit)
		}
	}

	return maxProfit
}

func main() {
	W := 10
	items := []Item{
		{1, 2, 40},
		{2, 5, 30},
		{3, 10, 50},
		{4, 5, 10},
	}
	n := len(items)

	fmt.Println("=== Branch and Bound: 0/1 Knapsack ===")
	fmt.Printf("Capacity: %d\n\n", W)

	maxProfit := solveKnapsackBB(W, items, n)

	fmt.Printf("\nMaximum Profit: %d\n", maxProfit)

	fmt.Println()
	fmt.Print("Press Enter to exit...")
	bufio.NewReader(os.Stdin).ReadBytes('\n')
}
