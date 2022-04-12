class Solution {
    public boolean canPartition(int[] nums) {
        int sum = 0;
        for(int i = 0; i < nums.length; i++)
            sum += nums[i];
        // if 'sum' is a an odd number, we can't have two subsets with equal sum
        if(sum%2 != 0)
            return false;
        
        Boolean dp[][] = new Boolean[nums.length][sum/2 + 1];
        return canRecur(dp,nums,sum/2,0);
    }
    
    private boolean canRecur(Boolean dp[][], int nums[], int sum, int currIdx){
        // base check
        if(sum == 0)
            return true;
        if(nums.length == 0 || currIdx >= nums.length)
            return false;
        
        // if we have not already processed a similar problem
        if(dp[currIdx][sum] == null)
        {// recursive call after choosing the number at the currentIndex
         // if the number at currentIndex exceeds the sum, we shouldn't process this
            if(nums[currIdx] <= sum){
                if(canRecur(dp,nums,sum-nums[currIdx],currIdx+1)){
                    dp[currIdx][sum] = true;
                    return true;
                }
            }
            dp[currIdx][sum] = canRecur(dp,nums,sum,currIdx+1);
        }
        
        return dp[currIdx][sum];
    } 
}