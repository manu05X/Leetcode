class Solution {
    public int findUnsortedSubarray(int[] nums) {
        // Initialize variables
        final int MAX_INT = Integer.MAX_VALUE; // Use MAX_VALUE constant for clarity
        int n = nums.length; // Length of the input array
        int leftIndex = -1, rightIndex = -1; // Track the left and right boundaries of the subarray
        int minUnsorted = MAX_INT, maxUnsorted = Integer.MIN_VALUE; // Set initial values for min and max of the unsorted subarray

        // Loop through the array to find the unsorted subarray's boundaries
        for (int i = 0; i < n; ++i) 
        {
            int lcurrElm = nums[i]; // elment from LHS
            int rcurrElm = nums[n - i - 1]; // elment from RHS
            // If current max is greater than the current element, it might belong to the unsorted part
            if (maxUnsorted > lcurrElm) {
                rightIndex = i; // Update the right boundary
            } else {
                maxUnsorted = lcurrElm; // Update the current max for the sorted part
            }
          
            // Simultaneously, check the unsorted subarray from the end of the array
            if (minUnsorted < rcurrElm) {
                leftIndex = n - i - 1; // Update the left boundary
            } else {
                minUnsorted = rcurrElm; // Update the current min for the sorted part
            }
        }
      
        // If rightIndex is not updated, the array is fully sorted, return 0
        // Otherwise, return the length of the subarray that must be sorted
        return rightIndex == -1 ? 0 : rightIndex - leftIndex + 1;
    }
}