class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end()); // Sort the array

        int right = 0; // Right pointer
        int maxBeauty = 0; // Maximum size of the range

        // Iterate with the left pointer
        for (int left = 0; left < n; left++) {
            // Expand the right pointer as long as the condition is satisfied
            while (right < n && nums[right] - nums[left] <= 2 * k) {
                right++;
            }

            // Update the maximum beauty
            maxBeauty = max(maxBeauty, right - left);
        }

        return maxBeauty;
    }
};