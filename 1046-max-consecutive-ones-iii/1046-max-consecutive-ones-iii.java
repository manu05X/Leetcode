class Solution {
    public int longestOnes(int[] nums, int k) {
        int zeroCount = k; // Number of zero's in the window.
        int longestWindow = 0;

        int l = 0;
        for(int r = 0; r < nums.length; r++){
            if(nums[r] == 0){
                zeroCount--;
            }
            // Shrink the window until the zero counts come under the limit.
            while(zeroCount < 0){
                if(nums[l] == 0){
                    zeroCount++;
                }
                l++;
            }

            longestWindow = Math.max(longestWindow, r-l+1);
        }

        return longestWindow;
    }
}