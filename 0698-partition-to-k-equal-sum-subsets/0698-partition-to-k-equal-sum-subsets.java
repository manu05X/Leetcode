class Solution {
    public boolean canPartitionKSubsets(int[] nums, int k) {
        int n = nums.length;
        int sum = 0;

        for(int i = 0; i < n; i++){
            sum += nums[i];
        }

        if(sum%k != 0){
            return false;
        }

        int targetSum = sum/k; // the subsets sum whose sum are all equal
        boolean[] visited = new boolean[n];

        return backtrack(nums, 0, 0, k, targetSum, visited);
    }

    boolean backtrack(int[] nums, int start, int currSum, int k, int targetSum, boolean[] visited){
        if(k == 0){
            return true; // All subsets found
        }

        if(currSum == targetSum){
            return backtrack(nums, 0, 0, k-1, targetSum, visited); // Move on to the next subset
        }
        for(int i = start; i < nums.length; i++){
            if(!visited[i] && currSum + nums[i] <= targetSum){
                visited[i] = true;
                if(backtrack(nums, i+1, currSum + nums[i], k, targetSum, visited)){
                    return true; // Found a valid subse
                }

                visited[i] = false; // backtrack

                // Prune the search space: if the current number doesn't fit in the current subset, it won't fit in any other subset
                if(currSum == 0){
                    break;
                }
                // Prune the search space: skip duplicates to avoid redundant computations
                while(i+1 < nums.length && nums[i] == nums[i+1]){
                    i++;
                }
            }
        }

        return false;
    }
}