class Solution {
    public int findMiddleIndex(int[] nums) {
        int n = nums.length;
        int[] arrSum = new int[n];
        int rightSum = 0;

        for(int i = 0; i < n; i++){
            rightSum += nums[i];
        }

        int leftSum = 0;

        for(int i = 0; i < n; i++){
            rightSum -= nums[i];

            if(leftSum == rightSum){
                return i;
            }
            leftSum += nums[i];
        }

        return -1;
    }
}