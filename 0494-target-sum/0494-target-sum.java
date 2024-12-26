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