class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        
        vector<vector<unsigned long long>> dp(n+1, vector<unsigned long long>(m+1, 0));

        // If t is empty, there is one way to form an empty subsequence
        for (int i = 0; i <= n; i++) {
            dp[i][0] = 1;
        }

        // Fill DP table
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                // If s[i-1] == t[j-1], we have two choices:
                if (s[i-1] == t[j-1]) {
                    // Include s[i-1] in the subsequence: dp[i-1][j-1]
                    // Exclude s[i-1]: dp[i-1][j]
                    dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
                } else {
                    // Only Exclude s[i-1]: dp[i-1][j]
                    dp[i][j] = dp[i-1][j];
                }
            }
        }

        return dp[n][m];
    }
};
