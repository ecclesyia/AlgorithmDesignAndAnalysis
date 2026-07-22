package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

type Activity struct {
	id     int
	start  int
	finish int
}

func selectActivities(activities []Activity) {
	sort.Slice(activities, func(i, j int) bool {
		return activities[i].finish < activities[j].finish
	})

	fmt.Printf("Sorted Activities by Finish Time:\n")
	for _, act := range activities {
		fmt.Printf("  Activity ID %d: [%d, %d]\n", act.id, act.start, act.finish)
	}

	fmt.Printf("\nScheduling Decisions:\n")
	selectedCount := 0
	lastFinishTime := activities[0].finish
	fmt.Printf("  Selected Activity ID %d: [%d, %d] (First to finish)\n", activities[0].id, activities[0].start, activities[0].finish)
	selectedCount++

	for i := 1; i < len(activities); i++ {
		if activities[i].start >= lastFinishTime {
			fmt.Printf("  Selected Activity ID %d: [%d, %d] (Starts after last finish %d)\n", activities[i].id, activities[i].start, activities[i].finish, lastFinishTime)
			lastFinishTime = activities[i].finish
			selectedCount++
		} else {
			fmt.Printf("  Skipped Activity ID %d: [%d, %d] (Conflict)\n", activities[i].id, activities[i].start, activities[i].finish)
		}
	}
	fmt.Printf("\nTotal selected compatible activities: %d\n", selectedCount)
}

func main() {
	activities := []Activity{
		{1, 5, 9},
		{2, 1, 2},
		{3, 3, 4},
		{4, 0, 6},
		{5, 5, 7},
		{6, 8, 9},
	}
	selectActivities(activities)
	fmt.Printf("\nPress Enter to exit...")
	bufio.NewReader(os.Stdin).ReadBytes('\n')
}
