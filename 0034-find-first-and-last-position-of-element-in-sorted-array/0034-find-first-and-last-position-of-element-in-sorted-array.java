class Solution {
    public int[] searchRange(int[] nums, int target) {
        int n = nums.length;

        int[] ans = new int[2];
        Arrays.fill(ans, -1);

        if(n == 0){
            return ans;
        }

        int lo = 0;
        int hi = n-1;

        while(lo < hi){
            int mid = (hi+lo)/2;

            if(nums[mid] < target){
                lo = mid+1;
            } else {
                hi = mid;
            }
        }

        if(nums[lo] != target)
        {
            return ans;
        }
        else
        {
            ans[0] = lo;
        }
        
        hi = n-1;
        while(lo < hi){
            int mid = (lo+hi)/2 + 1;

            if(nums[mid] > target){
                hi = mid-1;
            } else {
                lo = mid;
            }
        }

        ans[1] = lo;

        return ans;
    }
}