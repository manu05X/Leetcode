class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0; // Edge case: if nums is empty, return 0.

        vector<int> LIS(n, 1);   // LIS[i] stores the length of the LIS ending at index i.
        vector<int> count(n, 1); // count[i] stores the number of LIS ending at index i.

        int maxLength = 1; // Stores the maximum length of LIS found.

        // Iterate over each element in nums.
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) { // Check if we can extend the LIS
                    if (LIS[j] + 1 > LIS[i]) { // Found a longer LIS ending at i
                        LIS[i] = LIS[j] + 1;
                        count[i] = count[j]; // Reset count[i] to count[j]
                    } else if (LIS[j] + 1 == LIS[i]) { // Another LIS of the same length
                        count[i] += count[j]; // Add count[j] to count[i]
                    }
                }
            }
            maxLength = max(maxLength, LIS[i]); // Update the max LIS length found
        }

        int ans = 0; // Stores the total number of LIS
        for (int i = 0; i < n; i++) {
            if (LIS[i] == maxLength) { // Sum counts of all LIS with maxLength
                ans += count[i];
            }
        }

        return ans;
    }
};

