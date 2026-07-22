import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

public class activity_selection {
    public static class Activity {
        int id;
        int start;
        int finish;

        public Activity(int id, int start, int finish) {
            this.id = id;
            this.start = start;
            this.finish = finish;
        }
    }

    public static void selectActivities(Activity[] activities) {
        Arrays.sort(activities, new Comparator<Activity>() {
            @Override
            public int compare(Activity a, Activity b) {
                return Integer.compare(a.finish, b.finish);
            }
        });

        System.out.println("Sorted Activities by Finish Time:");
        for (Activity act : activities) {
            System.out.println("  Activity ID " + act.id + ": [" + act.start + ", " + act.finish + "]");
        }
        System.out.println("\nScheduling Decisions:");
        int selectedCount = 0;
        int lastFinishTime = activities[0].finish;
        System.out.println("  Selected Activity ID " + activities[0].id + ": [" + activities[0].start + ", " + activities[0].finish + "] (First to finish)");
        selectedCount++;

        for (int i = 1; i < activities.length; i++) {
            Activity act = activities[i];
            if (act.start >= lastFinishTime) {
                System.out.println("  Selected Activity ID " + act.id + ": [" + act.start + ", " + act.finish + "] (Starts after last finish " + lastFinishTime + ")");
                lastFinishTime = act.finish;
                selectedCount++;
            } else {
                System.out.println("  Skipped Activity ID " + act.id + ": [" + act.start + ", " + act.finish + "] (Conflict)");
            }
        }
        System.out.println("\nTotal selected compatible activities: " + selectedCount);
    }

    public static void main(String[] args) {
        Activity[] activities = {
            new Activity(1, 5, 9),
            new Activity(2, 1, 2),
            new Activity(3, 3, 4),
            new Activity(4, 0, 6),
            new Activity(5, 5, 7),
            new Activity(6, 8, 9)
        };
        selectActivities(activities);
        System.out.println();
        System.out.print("Press Enter to exit...");
        Scanner scanner = new Scanner(System.in);
        scanner.nextLine();
        scanner.close();
    }
}
