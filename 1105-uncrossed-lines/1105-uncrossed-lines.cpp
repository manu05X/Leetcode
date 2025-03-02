class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        // Get the sizes of both input arrays
        int n1 = nums1.size();
        int n2 = nums2.size();

        // Create a 2D DP table initialized with zeros
        // dp[i][j] represents the maximum number of uncrossed lines
        // that can be formed using the first 'i' elements of nums1 and first 'j' elements of nums2
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));

        // Fill the DP table using bottom-up approach
        for (int i = 1; i <= n1; i++) {
            for (int j = 1; j <= n2; j++) {
                // If the current elements match, we take the value from the previous diagonal cell and add 1
                if (nums1[i - 1] == nums2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    // Otherwise, take the maximum from the previous row or column
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        // The last cell of the table contains the final answer
        return dp[n1][n2];
    }
};



/*
class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();

        vector<int> dp(n2 + 1), dpPrev(n2 + 1);

        for (int i = 1; i <= n1; i++) {
            for (int j = 1; j <= n2; j++) {
                if (nums1[i - 1] == nums2[j - 1]) {
                    dp[j] = 1 + dpPrev[j - 1];
                } else {
                    dp[j] = max(dp[j - 1], dpPrev[j]);
                }
            }
            dpPrev = dp;
        }

        return dp[n2];
    }
};
*/