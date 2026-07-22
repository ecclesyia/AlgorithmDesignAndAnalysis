#include <stdio.h>
#include <stdlib.h>

/*
 * Session 04: Activity Selection in C
 * Uses a greedy strategy by scheduling activities sorted by their finish times.
 */

typedef struct {
    int id;
    int start;
    int finish;
} Activity;

// Comparison function for qsort. Sorts activities in ascending order of finish time.
int compareActivities(const void *a, const void *b) {
    Activity *actA = (Activity *)a;
    Activity *actB = (Activity *)b;
    return (actA->finish - actB->finish);
}

void selectActivities(Activity activities[], int size) {
    // 1. Sort activities by finish time ascending
    qsort(activities, size, sizeof(Activity), compareActivities);

    printf("Sorted Activities by Finish Time:\n");
    for (int i = 0; i < size; i++) {
        printf("  Activity ID %d: [%d, %d]\n", 
               activities[i].id, activities[i].start, activities[i].finish);
    }
    printf("\n");

    printf("Scheduling Decisions:\n");
    
    // The first activity is always selected because it finishes first
    int selectedCount = 0;
    int lastFinishTime = activities[0].finish;
    printf("  Selected Activity ID %d: [%d, %d] (First to finish)\n", 
           activities[0].id, activities[0].start, activities[0].finish);
    selectedCount++;

    // Iterate through the rest of the activities
    for (int i = 1; i < size; i++) {
        // If start time is greater than or equal to the finish time of the last selected activity, select it
        if (activities[i].start >= lastFinishTime) {
            printf("  Selected Activity ID %d: [%d, %d] (Starts after last finish %d)\n", 
                   activities[i].id, activities[i].start, activities[i].finish, lastFinishTime);
            lastFinishTime = activities[i].finish;
            selectedCount++;
        } else {
            printf("  Skipped Activity ID %d: [%d, %d] (Conflict: starts before last finish %d)\n", 
                   activities[i].id, activities[i].start, activities[i].finish, lastFinishTime);
        }
    }

    printf("\nTotal selected compatible activities: %d\n", selectedCount);
}

int main() {
    Activity activities[] = {
        {1, 5, 9},
        {2, 1, 2},
        {3, 3, 4},
        {4, 0, 6},
        {5, 5, 7},
        {6, 8, 9}
    };
    int size = sizeof(activities) / sizeof(activities[0]);

    printf("=== Greedy Optimization: Activity Selection ===\n\n");

    selectActivities(activities, size);

    printf("\nPress Enter to exit...");
    getchar();
    return 0;
}
