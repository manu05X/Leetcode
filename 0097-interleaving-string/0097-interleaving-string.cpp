class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.length(); // Length of s1
        int m = s2.length(); // Length of s2
        int l = s3.length(); // Length of s3

        // If the combined length of s1 and s2 is not equal to s3, s3 cannot be an interleaving
        if (n + m != l) {
            return false;
        }

        // 1D DP array: dp[j] represents whether s3[0..i+j-1] is an interleaving of s1[0..i-1] and s2[0..j-1]
        vector<bool> dp(m + 1, false);

        // Base case: Both s1 and s2 are empty, so s3 is also empty (trivially true)
        dp[0] = true;

        // Initialize the dp array for the case when s1 is empty.
        for (int j = 1; j <= m; j++) {
            dp[j] = dp[j - 1] && (s2[j - 1] == s3[j - 1]);
        }

        // Fill the DP array for the general case
        for (int i = 1; i <= n; i++) {
            // Store the previous value of dp[0] (for the case when j = 0)
            bool prev = dp[0];
            // Update dp[0] for the current row
            dp[0] = prev && (s1[i - 1] == s3[i - 1]);

            for (int j = 1; j <= m; j++) {
                // Store the current value of dp[j] before updating it
                bool temp = dp[j];
                // Update dp[j] for the current row
                // Check if the current character of s1 can be used (and dp[j] was true from previous row)
                // or if the current character of s2 can be used (and dp[j-1] was true in current row).
                dp[j] = (dp[j] && (s1[i - 1] == s3[i + j - 1])) || 
                        (dp[j - 1] && (s2[j - 1] == s3[i + j - 1]));
                // Update prev for the next iteration
                prev = temp;
            }
        }

        // The result is stored in dp[m], which represents whether s3 is an interleaving of s1 and s2
        return dp[m];
    }
};


/*
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.length(); // Length of string s1
        int m = s2.length(); // Length of string s2
        int l = s3.length(); // Length of string s3

        // If the combined length of s1 and s2 is not equal to s3, s3 cannot be an interleaving
        if (s1.length() + s2.length() != s3.length()) {
            return false;
        }

        // DP table: dp[i][j] will be true if s3[0..i+j-1] is an interleaving of s1[0..i-1] and s2[0..j-1]
        bool dp[n + 1][m + 1];

        // Fill the DP table
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
                // Base case: Both s1 and s2 are empty, so s3 is also empty (trivially true)
                if (i == 0 && j == 0) {
                    dp[i][j] = true;
                }
                // Case 1: s1 is empty, so check if s2 matches s3
                else if (i == 0) {
                    dp[i][j] = dp[i][j - 1] && (s2[j - 1] == s3[i + j - 1]);
                }
                // Case 2: s2 is empty, so check if s1 matches s3
                else if (j == 0) {
                    dp[i][j] = dp[i - 1][j] && (s1[i - 1] == s3[i + j - 1]);
                }
                // Case 3: Both s1 and s2 are non-empty
                // Check if the current character of s3 matches either s1 or s2, and the previous state is true
                else {
                    dp[i][j] = (dp[i - 1][j] && (s1[i - 1] == s3[i + j - 1])) || 
                               (dp[i][j - 1] && (s2[j - 1] == s3[i + j - 1]));
                }
            }
        }

        // The result is stored in dp[n][m], which represents whether s3 is an interleaving of s1 and s2
        return dp[n][m];
    }
};
*/