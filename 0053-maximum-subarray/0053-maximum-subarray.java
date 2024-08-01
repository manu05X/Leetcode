class Solution {
    public int maxSubArray(int[] nums) {
        // `maxSoFar` holds the maximum subarray sum found so far
        int maxSoFar = nums[0];
        // `currentMax` holds the maximum sum of the subarray ending at the current position
        int currentMax = nums[0];
      
        // Loop through the array starting from the second element
        for (int i = 1; i < nums.length; ++i) {
            // Update `currentMax` to be the maximum of `currentMax` + current element or 0 + current element
            // This is the essence of the Kadane's algorithm which decides whether to start a new subarray or continue with the current one
            currentMax = Math.max(currentMax, 0) + nums[i];
          
            // If the current computed `currentMax` is greater than `maxSoFar`, update `maxSoFar`
            maxSoFar = Math.max(maxSoFar, currentMax);
        }
        // Return the largest sum
        return maxSoFar;
    }
}