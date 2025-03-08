class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int total = 0;
        // Calculate the total sum of the array
        for (int num : nums) {
            total += num;
        }

        // If the target is greater than the total sum or less than -total, it's impossible to achieve
        if (total < abs(target)) {
            return 0;
        }

        // Initialize a DP table
        // dp[i][j] represents the number of ways to achieve sum (j - total) using the first i elements
        int n = nums.size();
        int dp[n][2 * total + 1];
        memset(dp, 0, sizeof(dp)); // Initialize the DP table to 0

        // Base case: Using the first element, we can either add or subtract it
        dp[0][total + nums[0]] = 1; // Adding nums[0]
        dp[0][total - nums[0]] += 1; // Subtracting nums[0]

        // Fill the DP table
        for (int i = 1; i < n; ++i) {
            for (int t = -total; t <= total; ++t) {
                // If there are ways to achieve sum t using the first (i-1) elements
                if (dp[i - 1][total + t] > 0) {
                    // Add nums[i] to the sum
                    dp[i][total + t + nums[i]] += dp[i - 1][total + t];
                    // Subtract nums[i] from the sum
                    dp[i][total + t - nums[i]] += dp[i - 1][total + t];
                }
            }
        }

        // The answer is the number of ways to achieve the target sum using all elements
        return dp[n - 1][total + target];
    }
};





/*
class Solution {
public:
    int findTargetSumWaysRec(vector<int>& nums, int idx, int target){
         // If all integers are processed
        if(idx == nums.size()){
            // If target is reached
            if(target == 0){
                return 1;
            }
            // If target is not reached
            return 0;
        }

        // Return total count of the following cases:
        //       1. Add current element to the target
        //       2. Subtract current element from the target
        return (findTargetSumWaysRec(nums, idx+1, target-nums[idx]) + findTargetSumWaysRec(nums, idx+1, target+nums[idx]));
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        return findTargetSumWaysRec(nums, 0, target);
    }
};

*/