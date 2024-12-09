class Solution {
public:
    // Function to check if the array can be split into at most `k` subarrays
    // such that no subarray's sum exceeds `maxSum`.
    bool canBeSplit(vector<int>& nums, int k, int maxSum) {
        int currSum = 0;  // Keeps track of the current subarray sum
        int subarrays = 1; // Number of subarrays formed so far

        // Iterate through each element in the array
        for (int i = 0; i < nums.size(); i++) {
            // If adding the current element exceeds maxSum, start a new subarray
            if (currSum + nums[i] > maxSum) {
                subarrays++;
                currSum = nums[i]; // Start new subarray with the current element
                // If the number of subarrays exceeds `k`, return false
                if (subarrays > k) {
                    return false;
                }
            } else {
                currSum += nums[i]; // Add current element to the current subarray
            }
        }
        return true; // The array can be split with the given maxSum
    }

    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        int left = 0;   // Initialize left to the maximum element (minimum possible largest sum)
        for(int num : nums){
            left = max(left, num);
        }

        int right = 0;  // Initialize right to the sum of all elements (maximum possible largest sum)

        // Calculate the sum of all elements (upper limit for the binary search)
        for (int i = 0; i < n; i++) {
            right += nums[i];
        }

        int ans = right; // Initialize the answer to the upper limit

        // Perform binary search
        while (left <= right) {
            int mid = left + (right - left) / 2; // Calculate the middle point

            // Check if the array can be split with the current mid as max sum
            if (canBeSplit(nums, k, mid)) {
                ans = mid;   // Update the answer to the current mid
                right = mid - 1; // Search in the smaller range
            } else {
                left = mid + 1; // Search in the larger range
            }
        }

        return ans; // Return the minimized largest sum
    }
};
