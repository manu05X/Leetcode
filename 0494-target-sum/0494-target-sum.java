
public class Solution {

    public int findTargetSumWays(int[] nums, int target) {
        int totalSum = Arrays.stream(nums).sum();
        int[][] dp = new int[nums.length][2 * totalSum + 1];

        // Initialize the first row of the DP table
        dp[0][nums[0] + totalSum] = 1;
        dp[0][-nums[0] + totalSum] += 1;

        // Fill the DP table
        for (int index = 1; index < nums.length; index++) {
            for (int sum = -totalSum; sum <= totalSum; sum++) {
                if (dp[index - 1][sum + totalSum] > 0) {
                    dp[index][sum + nums[index] + totalSum] += dp[index -
                        1][sum + totalSum];
                    dp[index][sum - nums[index] + totalSum] += dp[index -
                        1][sum + totalSum];
                }
            }
        }

        // Return the result if the target is within the valid range
        return Math.abs(target) > totalSum
            ? 0
            : dp[nums.length - 1][target + totalSum];
    }
}


/*
class Solution {
    int n = 0;
    int totalSum = 0;

    public int findTargetSumWays(int[] nums, int target) {
        n = nums.length;
        totalSum = Arrays.stream(nums).sum();
        int [][] memo = new int[n][2*totalSum+1];

        for(int[] row : memo){
            Arrays.fill(row, Integer.MIN_VALUE);
        }

        return dfs(nums, 0, 0, target, memo);
    }

    private int dfs(int[] nums, int currIdx, int currSum ,int target, int[][] memo){
        // if current index is equal to the length of nums
        if(currIdx == n){
            // if target is current Sum so, increase ans
            if(currSum == target){
                return 1;
            } else{
                return 0;
            }
        } else{
            if(memo[currIdx][currSum+totalSum] != Integer.MIN_VALUE){
                return memo[currIdx][currSum+totalSum];
            }

            // add the curr(currIdx) nums element to currSum, and increase the index by 1
            int add = dfs(nums, currIdx+1, currSum+nums[currIdx], target, memo);
            // Subbtract the curr(currIdx) nums element to currSum and increase the index by 1
            int sub = dfs(nums, currIdx+1, currSum-nums[currIdx], target, memo);

            memo[currIdx][currSum+totalSum] = add + sub;
            return memo[currIdx][currSum+totalSum];
        }
    }
}

*/

/*

Time complexity: O(2^n) i.e exponential

class Solution {
    int ans = 0;
    int n = 0;
    public int findTargetSumWays(int[] nums, int target) {
        n = nums.length;
        dfs(nums, 0, 0, target);

        return ans;
    }

    private void dfs(int[] nums, int currIdx, int currSum ,int target){
        // if current index is equal to the length of nums
        if(currIdx == n){
            // if target is current Sum so, increase ans
            if(currSum == target){
                ans++;
            }
        } else{
            // add the curr(currIdx) nums element to currSum, and increase the index by 1
            dfs(nums, currIdx+1, currSum+nums[currIdx], target);
            // Subbtract the curr(currIdx) nums element to currSum and increase the index by 1
            dfs(nums, currIdx+1, currSum-nums[currIdx], target);
        }


    }
}


 */