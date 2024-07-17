class Solution {
    public int findUnsortedSubarray(int[] nums) {
        int n = nums.length;

        // Find the leftmost and rightmost elements that are out of order
        int left = 0, right = n - 1;
        while (left < n - 1 && nums[left] <= nums[left + 1]) {
            left++;
        }
        while (right > 0 && nums[right] >= nums[right - 1]) {
            right--;
        }

        // If the array is already sorted, return 0
        if (left >= right) {
            return 0;
        }

        // Find the minimum and maximum values within the subarray [left, right]
        int minVal = Integer.MAX_VALUE, maxVal = Integer.MIN_VALUE;
        for (int i = left; i <= right; i++) {
            minVal = Math.min(minVal, nums[i]);
            maxVal = Math.max(maxVal, nums[i]);
        }

        // Expand the subarray to include elements that are greater than minVal
        while (left > 0 && nums[left - 1] > minVal) {
            left--;
        }

        // Expand the subarray to include elements that are less than maxVal
        while (right < n - 1 && nums[right + 1] < maxVal) {
            right++;
        }

        // Return the length of the unsorted subarray
        return right - left + 1;
    }
}