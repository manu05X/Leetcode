class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        if (costs.empty()) return 0;
        
        int n = costs.size();    // Number of houses
        int k = costs[0].size(); // Number of colors
        
        // DP table: dp[i][j] represents the minimum cost to paint house i with color j
        vector<vector<int>> dp(n, vector<int>(k, 0));
        
        // Initialize the first row of the DP table
        for (int j = 0; j < k; ++j) {
            dp[0][j] = costs[0][j];
        }
        
        // Fill the DP table
        for (int i = 1; i < n; ++i) {
            // Precompute the minimum and second minimum costs from the previous row
            int min1 = INT_MAX, min2 = INT_MAX;
            int minColor = -1;
            
            for (int j = 0; j < k; ++j) {
                if (dp[i-1][j] < min1) {
                    min2 = min1;
                    min1 = dp[i-1][j];
                    minColor = j;
                } else if (dp[i-1][j] < min2) {
                    min2 = dp[i-1][j];
                }
            }
            
            // Calculate the current row's DP values
            for (int j = 0; j < k; ++j) {
                if (j == minColor) {
                    // If the current color is the same as the minimum color, use the second minimum
                    dp[i][j] = costs[i][j] + min2;
                } else {
                    // Otherwise, use the minimum
                    dp[i][j] = costs[i][j] + min1;
                }
            }
        }
        
        // Find the minimum cost in the last row
        int result = INT_MAX;
        for (int j = 0; j < k; ++j) {
            result = min(result, dp[n-1][j]);
        }
        
        return result;
    }
};