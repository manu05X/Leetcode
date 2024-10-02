class Solution {
    public int threeSumClosest(int[] nums, int target) {
        int n = nums.length;
        int closestSum = Integer.MAX_VALUE;
        Arrays.sort(nums); // -4,-1,1,2

        for(int i = 0; i < n; i++)
        {
            int lo = i+1;
            int hi = n-1;
            while(lo < hi){
                int sum = nums[lo]+ nums[hi]+nums[i];
                //Update the closestSum if current sum is closest to target
                if(Math.abs(target - sum) < Math.abs(target-closestSum))
                {
                    closestSum = sum;
                }

                if(sum < target){
                    lo++;
                }
                else if(sum > target){
                    hi--;
                } else {
                    return sum;
                }
            }
        }
        return closestSum;
    }
}