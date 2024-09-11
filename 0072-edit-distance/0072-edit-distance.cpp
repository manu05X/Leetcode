class Solution {
public:
    // Function to calculate the minimum number of operations required 
    // to convert word1 to word2 using Dynamic Programming
    int minDistance(string word1, string word2) {
        // Get the lengths of the two words
        int m = word1.size();
        int n = word2.size();
        
        // Create a 2D DP table to store the minimum operations required
        // Initialize the table with size (m+1) x (n+1) filled with 0s
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        // Fill the first column (converting word1 to an empty string)
        // It will take 'i' deletions to convert the first i characters of word1 to an empty string
        for (int i = 1; i <= m; i++) 
        {
            dp[i][0] = i;
        }

        // Fill the first row (converting an empty string to word2)
        // It will take 'j' insertions to convert an empty string to the first j characters of word2
        for (int j = 1; j <= n; j++) 
        {
            dp[0][j] = j;
        }

        // Fill the rest of the DP table
        for (int i = 1; i <= m; i++) 
        {
            for (int j = 1; j <= n; j++) 
            {
                // If the characters from both words match, no new operation is needed.
                // So, we carry over the previous value from dp[i-1][j-1].
                if (word1[i - 1] == word2[j - 1]) 
                {
                    dp[i][j] = dp[i - 1][j - 1];
                } 
                else 
                {
                    // If the characters are different, we need to consider:
                    // - Substituting (dp[i-1][j-1]), 
                    // - Inserting (dp[i][j-1]), 
                    // - Deleting (dp[i-1][j]).
                    // We choose the minimum of these three operations and add 1 (for the current operation).
                    dp[i][j] = min({dp[i - 1][j - 1], dp[i][j - 1], dp[i - 1][j]}) + 1;
                }
            }
        }

        // The final answer will be in dp[m][n], which represents the minimum number
        // of operations to convert word1 to word2
        return dp[m][n];
    }
};
