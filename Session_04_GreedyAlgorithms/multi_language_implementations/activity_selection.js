const readline = require('readline');

function selectActivities(activities) {
    const sortedActivities = [...activities].sort((a, b) => a.finish - b.finish);
    console.log("Sorted Activities by Finish Time:");
    for (let act of sortedActivities) {
        console.log(`  Activity ID ${act.id}: [${act.start}, ${act.finish}]`);
    }

    console.log("\nScheduling Decisions:");
    let selectedCount = 0;
    let lastFinishTime = sortedActivities[0].finish;
    console.log(`  Selected Activity ID ${sortedActivities[0].id}: [${sortedActivities[0].start}, ${sortedActivities[0].finish}] (First to finish)`);
    selectedCount++;

    for (let i = 1; i < sortedActivities.length; i++) {
        const act = sortedActivities[i];
        if (act.start >= lastFinishTime) {
            console.log(`  Selected Activity ID ${act.id}: [${act.start}, ${act.finish}] (Starts after last finish ${lastFinishTime})`);
            lastFinishTime = act.finish;
            selectedCount++;
        } else {
            console.log(`  Skipped Activity ID ${act.id}: [${act.start}, ${act.finish}] (Conflict)`);
        }
    }
    console.log(`\nTotal selected compatible activities: ${selectedCount}`);
}

function main() {
    const activities = [
        {id: 1, start: 5, finish: 9},
        {id: 2, start: 1, finish: 2},
        {id: 3, start: 3, finish: 4},
        {id: 4, start: 0, finish: 6},
        {id: 5, start: 5, finish: 7},
        {id: 6, start: 8, finish: 9}
    ];
    selectActivities(activities);
    console.log();

    const rl = readline.createInterface({
        input: process.stdin,
        output: process.stdout
    });
    rl.question("Press Enter to exit...", () => {
        rl.close();
    });
}

main();
