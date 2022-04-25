class Solution {
    public int maxProduct(int[] nums) {
        if(nums.length == 0)
            return 0;
        
        int maxFar = nums[0];
        int minFar = nums[0];
        int res = maxFar;
        
        for(int i = 1; i < nums.length; i++)
        {
            int curr = nums[i];
            int tempMax = Math.max(curr,Math.max(maxFar*curr,minFar*curr));
            minFar = Math.min(curr, Math.min(maxFar*curr,minFar*curr));
            
            maxFar = tempMax;
            
            res = Math.max(maxFar,res);
            
        }
        
        return res;
    }
}