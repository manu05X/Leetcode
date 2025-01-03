class Solution {
    public int waysToSplitArray(int[] nums) {
        int n = nums.length;
        long totalSum = 0;

        for(int x : nums){
            totalSum += x;
        }

        long leftSum = 0;
        int count = 0;

        for(int i = 0; i < n-1; i++){
            leftSum += nums[i];

            long rightSum = totalSum - leftSum;

            if(leftSum >= rightSum){
                count++;
            }
        }


        return count;
    }
}