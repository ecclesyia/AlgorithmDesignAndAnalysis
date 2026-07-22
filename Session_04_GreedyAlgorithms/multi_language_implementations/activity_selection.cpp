#include <iostream>
#include <vector>
#include <algorithm>

struct Activity {
    int id;
    int start;
    int finish;
};

bool compareActivities(const Activity &a, const Activity &b) {
    return (a.finish < b.finish);
}

void selectActivities(std::vector<Activity> &activities) {
    std::sort(activities.begin(), activities.end(), compareActivities);
    std::cout << "Sorted Activities by Finish Time:\n";
    for (size_t i = 0; i < activities.size(); i++) {
        std::cout << "  Activity ID " << activities[i].id << ": [" << activities[i].start << ", " << activities[i].finish << "]\n";
    }
    std::cout << "\nScheduling Decisions:\n";
    int selectedCount = 0;
    int lastFinishTime = activities[0].finish;
    std::cout << "  Selected Activity ID " << activities[0].id << ": [" << activities[0].start << ", " << activities[0].finish << "] (First to finish)\n";
    selectedCount++;
    for (size_t i = 1; i < activities.size(); i++) {
        if (activities[i].start >= lastFinishTime) {
            std::cout << "  Selected Activity ID " << activities[i].id << ": [" << activities[i].start << ", " << activities[i].finish << "] (Starts after last finish " << lastFinishTime << ")\n";
            lastFinishTime = activities[i].finish;
            selectedCount++;
        } else {
            std::cout << "  Skipped Activity ID " << activities[i].id << ": [" << activities[i].start << ", " << activities[i].finish << "] (Conflict)\n";
        }
    }
    std::cout << "\nTotal selected compatible activities: " << selectedCount << "\n";
}

int main() {
    std::vector<Activity> activities = {{1, 5, 9}, {2, 1, 2}, {3, 3, 4}, {4, 0, 6}, {5, 5, 7}, {6, 8, 9}};
    selectActivities(activities);
    std::cout << "\nPress Enter to exit...";
    std::cin.get();
    return 0;
}
