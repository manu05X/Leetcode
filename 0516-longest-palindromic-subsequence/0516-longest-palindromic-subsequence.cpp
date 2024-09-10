class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();

        vector<vector<int>> dp(n, vector<int>(n));

        for(int gap = 0; gap < n; gap++){
            //every word start from 0 go till gap
            for(int i = 0, j = gap; j < n; i++, j++){
                if(gap == 0){
                    dp[i][j] = 1;
                }
                else if(gap == 1){
                    //if extreme char is same then put 2 else 1
                    dp[i][j] = s[i] == s[j]? 2:1;
                } else {
                    //if extream char is same
                    if(s[i] == s[j]){
                        dp[i][j] = dp[i+1][j-1]+2;
                    } else {
                        //if extream char is not same
                        dp[i][j] = max(dp[i][j-1],dp[i+1][j]); // max(prefix, suffix)
                    }
                }
            }
        }
        // ans is present in top right corner 
        return dp[0][n-1];
    }
};