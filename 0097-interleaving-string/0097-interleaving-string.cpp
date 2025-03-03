class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.size(), n = s2.size();
        // If the lengths don't add up, s3 cannot be an interleaving.
        if(m + n != s3.size()) return false;
        
        // dp[j] represents whether s1[0..i-1] and s2[0..j-1] can interleave to form s3[0..i+j-1].
        vector<bool> dp(n + 1, false);
        dp[0] = true;
        
        // Initialize the dp array for the case when s1 is empty.
        for (int j = 1; j <= n; j++) {
            dp[j] = dp[j - 1] && (s2[j - 1] == s3[j - 1]);
        }
        
        // Iterate over s1.
        for (int i = 1; i <= m; i++) {
            // Update dp[0] for the case when s2 is empty.
            dp[0] = dp[0] && (s1[i - 1] == s3[i - 1]);
            
            // Update dp[j] for j from 1 to n.
            for (int j = 1; j <= n; j++) {
                // Check if the current character of s1 can be used (and dp[j] was true from previous row)
                // or if the current character of s2 can be used (and dp[j-1] was true in current row).
                dp[j] = (dp[j] && (s1[i - 1] == s3[i + j - 1])) ||
                        (dp[j - 1] && (s2[j - 1] == s3[i + j - 1]));
            }
        }
        
        return dp[n];
    }
};


/*
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.length();
        int m = s2.length();
        int l = s3.length();
        if(s1.length() + s2.length() != s3.length())
        {
            return false;
        }
        
        bool dp[n+1][m+1];
        
        for(int i = 0; i <= n; i++)
        {
            for(int j = 0; j <= m; j++)
            {
                if(i == 0 && j == 0)
                {
                    dp[i][j] = true;
                }
                else if(i == 0){
                    dp[i][j] = dp[i][j-1] && s2[j-1] == s3[i+j-1];
                }
                else if(j == 0){
                    dp[i][j] = dp[i-1][j] && s1[i-1] == s3[i+j-1];
                }
                else
                {
                    dp[i][j] = (dp[i - 1][j] && s1[i - 1] == s3[i + j - 1]) || (dp[i][j - 1] && s2[j - 1] == s3[i + j - 1]);
                }
            }
        }
        
        return dp[n][m];
    }
};
*/