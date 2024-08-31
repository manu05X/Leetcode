class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        // Step 1: Create a frequency array (or count array) of size 10,001.
        vector<int> points(1e4 + 1, 0);

        // Step 2: Calculate the total points for each number
        for (auto num : nums) {
            points[num] += num;
        }

        // Step 3: Initialize two variables: 'exc' and 'inc'.
        int excludeCurrent = 0;
        int includeCurrent = 0;

        // Iterate through all possible numbers (1 to 10000)
        for (int i = 0; i <= 10000; i++) {
            // Step 4: Iterate through the frequency array and calculate maximum points.
            int tempInclude = excludeCurrent + points[i]; // Points if current number is included
            int tempExclude = max(excludeCurrent, includeCurrent); // Points if current number is excluded

             // Update 'exc' to the maximum points excluding current number
            excludeCurrent = tempExclude;
            includeCurrent = tempInclude;// Update 'inc' to the points including current number
        }

        return max(excludeCurrent, includeCurrent);
    }
};
