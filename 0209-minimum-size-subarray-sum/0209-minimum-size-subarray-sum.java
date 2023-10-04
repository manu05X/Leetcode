class Solution {
    public int minSubArrayLen(int target, int[] nums) {
        int n = nums.length;
        int start = 0;
        int total = 0;
        int windowSize = Integer.MAX_VALUE;


        for(int i = 0; i < n; i++){
            total += nums[i];

            while(total >= target){
                int currWindow = (i+1)-start;
                windowSize = Math.min(windowSize, currWindow);
                total -= nums[start];
                start++;
            }
        }

        if(windowSize != Integer.MAX_VALUE)
            return windowSize;
        else
            return 0;
    }
}