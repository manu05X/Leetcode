class Solution {
    public int[] productExceptSelf(int[] nums) {
        int temp = 1;
        int[] ans = new int[nums.length];
        // Product of elements on left side excluding nums[i]
        for(int i = 0; i < nums.length; i++)
        {
            ans[i] = temp;
            temp *= nums[i];
        } 
        //ans = [1,1,2,6]
        // Initializing temp to 1 for product on right side
        temp = 1; 

        // Product of elements on right side excluding nums[i] 
        for(int i = nums.length - 1; i >= 0; i--)
        {
            ans[i]*= temp;
            temp *= nums[i];
        }
        // [24,12,8,6]
        return ans;
    }
}