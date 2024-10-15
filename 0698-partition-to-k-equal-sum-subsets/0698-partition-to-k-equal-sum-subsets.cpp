class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = 0;
        for (int num : nums) {
            sum += num;
        }

        if (sum % k != 0) {
            return false; // If the total sum is not divisible by k, return false
        }

        int targetSum = sum / k;
        int n = nums.size();
        vector<bool> visited(n, false);
        return canPartition(nums, visited, 0, k, 0, targetSum);
    }

    bool canPartition(vector<int>& nums, vector<bool>& visited, int start, int k, int curSum, int targetSum) {
        if (k == 0) {
            return true; // All subsets found
        }
        if (curSum == targetSum) {
            return canPartition(nums, visited, 0, k - 1, 0, targetSum); // Move on to the next subset
        }
        for (int i = start; i < nums.size(); ++i) {
            if (!visited[i] && curSum + nums[i] <= targetSum) {
                visited[i] = true;
                if (canPartition(nums, visited, i + 1, k, curSum + nums[i], targetSum)) {
                    return true; // Found a valid subset
                }
                visited[i] = false; // Backtrack
                // Prune the search space: if the current number doesn't fit in the current subset, it won't fit in any other subset
                if (curSum == 0) {
                    break;
                }
                // Prune the search space: skip duplicates to avoid redundant computations
                while (i + 1 < nums.size() && nums[i] == nums[i + 1]) {
                    ++i;
                }
            }
        }
        return false;
    }
};