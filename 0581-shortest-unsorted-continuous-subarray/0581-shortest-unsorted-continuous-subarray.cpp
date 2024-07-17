//revise
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        int start = -1; // Start position of the unsorted subarray
        int end = -2;   // End position of the unsorted subarray
        int minValue = nums[n - 1]; // Initialize to the last element to handle the case when the entire array is sorted
        int maxValue = nums[0]; // Initialize to the first element to handle the case when the entire array is sorted

        // Iterate from left to right to find the end position of the unsorted subarray
        for (int i = 1; i < n; ++i) {
            maxValue = max(maxValue, nums[i]);
            if (nums[i] < maxValue) {
                end = i;
            }
        }

        // Iterate from right to left to find the start position of the unsorted subarray
        for (int i = n - 2; i >= 0; --i) {
            minValue = min(minValue, nums[i]);
            if (nums[i] > minValue) {
                start = i;
            }
        }
        /*
        nums:{2, 6, 4, 8, 10, 9, 15}
        n:7
        start:1
        end:5
        minValue:2
        maxValue:15
        */

        // Calculate the length of the unsorted subarray
        return end - start + 1;
    }
};