class Solution {
public:
    int minInsertions(string s) {
        int n = s.length();
        // Reverse the string to find the Longest Palindromic Subsequence (LPS)
        string revS = s;
        reverse(revS.begin(), revS.end());
        
        // Compute the Longest Common Subsequence (LCS) of s and its reverse
        int lps = longestCommonSubsequence(s, revS);
        
        // Minimum insertions required to make s a palindrome
        return n - lps;
    }
    
private:
    int longestCommonSubsequence(string& s1, string& s2) {
        int n = s1.length();
        // DP table to store LCS values
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        // Compute LCS using bottom-up DP approach
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                // If characters match, extend LCS
                if (s1[i - 1] == s2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } 
                // Otherwise, take the maximum of ignoring one character
                else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        
        return dp[n][n]; // LCS length
    }
};


/*
class Solution {
public:
    int lcs(string& s1, string& s2, int m, int n) {
        vector<int> dp(n + 1), dpPrev(n + 1);

        for (int i = 0; i <= m; i++) {
            for (int j = 0; j <= n; j++) {
                if (i == 0 || j == 0) {
                    // One of the two strings is empty.
                    dp[j] = 0;
                } else if (s1[i - 1] == s2[j - 1]) {
                    dp[j] = 1 + dpPrev[j - 1];
                } else {
                    dp[j] = max(dpPrev[j], dp[j - 1]);
                }
            }
            dpPrev = dp;
        }

        return dp[n];
    }

    int minInsertions(string s) {
        int n = s.length();
        string sReverse = s;
        reverse(sReverse.begin(), sReverse.end());

        return n - lcs(s, sReverse, n, n);
    }
};

*/


// class Solution {
// public:
//     int minInsertions(string s) {
//         int n = s.size();
//         vector<int> dp_low(n, 0), dp(n, 0);
//         for(int i=n-1; i>=0; i--){
//             dp[i] = 1;
//             for(int j=i+1; j<n; j++){
//                 if(s[i] == s[j]) dp[j] = dp_low[j-1]+2;
//                 else dp[j] = max(dp[j-1], dp[j]);
//             }
//             dp_low = dp;
//         }
//         return n-dp[n-1];
//     }
// };