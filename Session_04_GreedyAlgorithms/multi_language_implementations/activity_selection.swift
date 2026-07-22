import Foundation

struct Activity {
    let id: Int
    let start: Int
    let finish: Int
}

func selectActivities(_ activities: [Activity]) {
    let sortedActivities = activities.sorted { $0.finish < $1.finish }
    print("Sorted Activities by Finish Time:")
    for act in sortedActivities {
        print("  Activity ID \(act.id): [\(act.start), \(act.finish)]")
    }

    print("\nScheduling Decisions:")
    var selectedCount = 0
    var lastFinishTime = sortedActivities[0].finish
    print("  Selected Activity ID \(sortedActivities[0].id): [\(sortedActivities[0].start), \(sortedActivities[0].finish)] (First to finish)")
    selectedCount += 1

    for i in 1..<sortedActivities.count {
        let act = sortedActivities[i]
        if act.start >= lastFinishTime {
            print("  Selected Activity ID \(act.id): [\(act.start), \(act.finish)] (Starts after last finish \(lastFinishTime))")
            lastFinishTime = act.finish
            selectedCount += 1
        } else {
            print("  Skipped Activity ID \(act.id): [\(act.start), \(act.finish)] (Conflict)")
        }
    }
    print("\nTotal selected compatible activities: \(selectedCount)")
}

func main() {
    let activities = [
        Activity(id: 1, start: 5, finish: 9),
        Activity(id: 2, start: 1, finish: 2),
        Activity(id: 3, start: 3, finish: 4),
        Activity(id: 4, start: 0, finish: 6),
        Activity(id: 5, start: 5, finish: 7),
        Activity(id: 6, start: 8, finish: 9)
    ]
    selectActivities(activities)
    print("\nPress Enter to exit...", terminator: "")
    fflush(stdout)
    let _ = readLine()
}

main()
