class Solution {
    // Helper function to check if the array can be split into at most k subarrays
    // with a maximum sum of maxSum
    public boolean canBeSplit(int[] nums, int k, int maxSum) {
        int currSum = 0;  // Current sum of the subarray
        int subarrays = 1; // Number of subarrays formed

        for (int num : nums) {
            // If adding the current number exceeds maxSum, start a new subarray
            if (currSum + num > maxSum) {
                subarrays++;
                currSum = num; // Start a new subarray
                // If the number of subarrays exceeds k, return false
                if (subarrays > k) {
                    return false;
                }
            } else {
                currSum += num; // Add the current number to the current subarray
            }
        }
        return true; // The array can be split with the given maxSum
    }

    public int splitArray(int[] nums, int k) {
        int left = 0;  // Initialize left to the maximum element (minimum possible largest sum)
        int right = 0; // Initialize right to the sum of all elements (maximum possible largest sum)

        for(int num : nums){
            left = Math.max(left, num);
        }

        // Calculate the sum of all elements (upper bound for binary search)
        for (int num : nums) {
            right += num;
        }

        int ans = right; // Initialize answer to the maximum possible sum

        // Perform binary search
        while (left <= right) {
            int mid = left + (right - left) / 2; // Calculate the middle point

            // Check if we can split the array with the current mid as max sum
            if (canBeSplit(nums, k, mid)) {
                ans = mid;   // Update answer to the current mid
                right = mid - 1; // Search in the smaller range
            } else {
                left = mid + 1; // Search in the larger range
            }
        }

        return ans; // Return the minimized largest sum
    }
}
