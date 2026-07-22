import java.util.Scanner

data class Activity(val id: Int, val start: Int, val finish: Int)

fun selectActivities(activities: List<Activity>) {
    val sortedActivities = activities.sortedBy { it.finish }
    println("Sorted Activities by Finish Time:")
    for (act in sortedActivities) {
        println("  Activity ID ${act.id}: [${act.start}, ${act.finish}]")
    }

    println("\nScheduling Decisions:")
    var selectedCount = 0
    var lastFinishTime = sortedActivities[0].finish
    println("  Selected Activity ID ${sortedActivities[0].id}: [${sortedActivities[0].start}, ${sortedActivities[0].finish}] (First to finish)")
    selectedCount++

    for (i in 1 until sortedActivities.size) {
        val act = sortedActivities[i]
        if (act.start >= lastFinishTime) {
            println("  Selected Activity ID ${act.id}: [${act.start}, ${act.finish}] (Starts after last finish $lastFinishTime)")
            lastFinishTime = act.finish
            selectedCount++
        } else {
            println("  Skipped Activity ID ${act.id}: [${act.start}, ${act.finish}] (Conflict)")
        }
    }
    println("\nTotal selected compatible activities: $selectedCount")
}

fun main() {
    val activities = listOf(
        Activity(1, 5, 9),
        Activity(2, 1, 2),
        Activity(3, 3, 4),
        Activity(4, 0, 6),
        Activity(5, 5, 7),
        Activity(6, 8, 9)
    )
    selectActivities(activities)
    println()
    print("Press Enter to exit...")
    Scanner(System.`in`).nextLine()
}
