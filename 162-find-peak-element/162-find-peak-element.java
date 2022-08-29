class Solution {
    public int findPeakElement(int[] nums) {
        int n = nums.length, res = 0;
        int h = Integer.MIN_VALUE;
        
        for(int i = 0; i < n; i++)
        {
            if(h < nums[i])
            {
                h = nums[i];
                res = i;
            }
        }
        
        return res;
    }
}