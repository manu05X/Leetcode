class Solution {
    public int[] searchRange(int[] nums, int target) {
        int n = nums.length;  // Get the length of the input array

        int[] ans = new int[2];  // Create an array to store the result (starting and ending index)
        Arrays.fill(ans, -1);  // Fill the result array with -1 (to represent the target not found case)

        if (n == 0) {  // If the array is empty, return [-1, -1]
            return ans;
        }

        int lo = 0;  // Initialize the low pointer (beginning of the array)
        int hi = n - 1;  // Initialize the high pointer (end of the array)

        // First binary search to find the leftmost occurrence of the target
        while (lo < hi) {
            int mid = (hi + lo) / 2;  // Calculate the mid index

            // If the middle element is less than the target, move the low pointer to mid+1
            if (nums[mid] < target) {
                lo = mid + 1;
            } else {
                // Otherwise, move the high pointer to mid (we are looking for the leftmost occurrence)
                hi = mid;
            }
        }

        // After the loop, lo will either point to the target or an element not equal to the target
        if (nums[lo] != target) {
            return ans;  // If the target is not found, return [-1, -1]
        } else {
            ans[0] = lo;  // Store the leftmost index of the target in ans[0]
        }

        // Now we need to find the rightmost occurrence of the target
        hi = n - 1;  // Reset the high pointer to the end of the array
        while (lo < hi) {
            int mid = (lo + hi) / 2 + 1;  // Calculate the mid index (with +1 to avoid infinite loops)

            // If the middle element is greater than the target, move the high pointer to mid-1
            if (nums[mid] > target) {
                hi = mid - 1;
            } else {
                // Otherwise, move the low pointer to mid (we are looking for the rightmost occurrence)
                lo = mid;
            }
        }

        ans[1] = lo;  // Store the rightmost index of the target in ans[1]

        return ans;  // Return the result array containing the leftmost and rightmost indices of the target
    }
}
