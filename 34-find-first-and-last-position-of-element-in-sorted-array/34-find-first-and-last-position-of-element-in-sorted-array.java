class Solution {
    public int[] searchRange(int[] nums, int target) {
        int l = 0;
        int h = nums.length-1;
        
        int[] ans = new int[2];
        ans[0] = -1;
        ans[1] = -1;
        if(nums.length < 1)
            return ans;
        while(l<h)
        {
            int m = (l+h)/2;
            if(nums[m] < target)
            {
                l = m+1;
            }
            else
            {
                h = m;
            }
        }
        
        if (nums[l]!=target) 
            return ans;
        else 
            ans[0] = l;
        
        h = nums.length-1;
        while(l < h)
        {
            int mid = (l + h) /2 + 1;	// Make mid biased to the right
            if (nums[mid] > target) 
                h = mid - 1;  
            else 
                l = mid;
        }
        
        ans[1] = h;
        
        return ans;
    }
}