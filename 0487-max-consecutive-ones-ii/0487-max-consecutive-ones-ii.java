class Solution {
    public int findMaxConsecutiveOnes(int[] nums) {
        int n = nums.length;
        int zeroCount = 1;
        int l = 0, maxLength = Integer.MIN_VALUE;

        for(int r = 0; r < n; r++){
            if(nums[r] == 0){
                zeroCount--;
            }

            while(zeroCount < 0)
            {
                if(nums[l] == 0)
                {
                    zeroCount++;
                }

                l++;
            }
            maxLength = Math.max(maxLength, r-l+1);
        }

        return maxLength;
    }
}