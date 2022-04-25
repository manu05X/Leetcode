class Solution {
    public int maxSubArray(int[] nums) {
        int mxSum = nums[0];
        int currSum = nums[0];
        
        for(int i = 1; i < nums.length; i++)
        {
            currSum = Math.max(nums[i],nums[i]+currSum);
            
            mxSum = Math.max(currSum, mxSum);
        }
        
        return mxSum;
    }
}