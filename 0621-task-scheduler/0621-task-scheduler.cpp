class Solution {
    // Dezerve interview
public:
    int leastInterval(vector<char>& tasks, int coolingPeriod) {
        int taskCount[26] = {0}; // Initialize a vector to keep count of each task
        int maxCount = 0; // Variable to keep track of the maximum count of a single task

        // Count the tasks and find out the task with the maximum count
        for (char task : tasks) {
            task = task - 'A'; // Convert char to an index between 0 and 25
            ++taskCount[task]; // Increment the count for this task
            maxCount = max(maxCount, taskCount[task]); // Update maxCount if current task's count is greater
        }

        // Count how many tasks have the same count as maxCount
        int tasksWithMaxCount = 0;
        for (int count : taskCount) {
            if (count == maxCount) {
                ++tasksWithMaxCount;
            }
        }

        // Calculate the least interval
        // First part: Calculate the minimum slots required based on the most frequent task (maxCount - 1) times (coolingPeriod + 1)
        // Second part: Add the number of tasks that have the highest frequency (taskWithMaxCount)
        int minSlotsRequired = (maxCount - 1) * (coolingPeriod + 1) + tasksWithMaxCount;

        // The result is the maximum between the actual size of tasks and the minimum slots required
        return max(((int)tasks.size()), minSlotsRequired);
    }
};
//Dezerve 