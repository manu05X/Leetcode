class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        if (nums.empty()) return 0;

        // Find the maximum number in nums
        int maxNum = *max_element(nums.begin(), nums.end());

        // Step 1: Create a frequency array (or count array) of size maxNum + 1
        // Create a count array to store the total points for each number
        vector<int> points(maxNum + 1, 0);

        // Step 2: Calculate the total points for each number
        for (auto num : nums) {
            points[num] += num;
        }

        // Step 3: Initialize two variables: 'exc' and 'inc'.
        int includeCurrent = 0; // maximum points up to (i-2)
        int includePrev = 0; // maximum points up to (i-1)

        // Step 4: Iterate through the frequency array and calculate maximum points.
        for (int i = 0; i <= maxNum; i++) {
            int tempInclude = includeCurrent + points[i]; // if current number is included: points(i-2)+points[i]
            int currNumber = max(tempInclude, includePrev); // max Points up to if current index 

             // Update 'exc' to the maximum points excluding current number
            includeCurrent = includePrev;
            includePrev = currNumber;// Update 'inc' to the points including current number
        }

        return max(includePrev, includeCurrent);
    }
};
