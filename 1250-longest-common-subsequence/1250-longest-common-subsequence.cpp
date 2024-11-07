class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length();
        int m = text2.length();

         vector<int> dp(m + 1, 0);
        // i and j represent the lengths of s1 and s2 respectively
        for(int i = 1; i <= n; i++){
            // prev stores the value from the previous 
            // row and previous column (i-1), (j -1)
            int prev = dp[0];  
            for(int j = 1; j <= m; j++){
                // temp temporarily stores the current dp[j] before it gets updated
                int temp = dp[j];
                if(text1[i-1] == text2[j-1])
                {
                    dp[j] = 1+prev;
                }
                else{
                    // Otherwise, take the maximum of the left and top values
                    dp[j] = max(dp[j], dp[j-1]);
                }
                prev = temp;
            }
        }

        return dp[m];
    }
};


/*
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length();
        int m = text2.length();

         vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(text1[i-1] == text2[j-1])
                {
                    dp[i][j] = dp[i-1][j-1] + 1;
                }
                else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }

        return dp[n][m];
    }
};
*/