class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        // Create a 2D DP table of size n x n initialized to 0
        vector<vector<int>> dp(n, vector<int>(n));

        // Traverse the string in reverse order (bottom-up DP)
        for (int i = n - 1; i >= 0; i--) {
            // Every single character is a palindrome of length 1
            dp[i][i] = 1;

            // Process substrings of increasing length
            for (int j = i + 1; j < n; j++) {
                // If characters at i and j match, extend the palindromic subsequence
                if (s[i] == s[j]) {
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                } 
                // Otherwise, take the maximum of skipping either i or j
                else {
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
                }
            }
        }

        // The final answer (LPS length) is stored at dp[0][n-1]
        return dp[0][n - 1];
    }
};




// class Solution {
// public:
//     int longestPalindromeSubseq(string s) {
//         int n = s.size();

//         vector<vector<int>> dp(n, vector<int>(n));

//         /*
//         for(int gap = 0; gap < n; gap++){
//             //every word start from 0 go till gap
//             for(int i = 0, j = gap; j < n; i++, j++){
//                 if(gap == 0){
//                     dp[i][j] = 1;
//                 }
//                 else if(gap == 1){
//                     //if extreme char is same then put 2 else 1
//                     dp[i][j] = s[i] == s[j]? 2:1;
//                 } else {
//                     //if extream char is same
//                     if(s[i] == s[j]){
//                         dp[i][j] = dp[i+1][j-1]+2;
//                     } else {
//                         //if extream char is not same
//                         dp[i][j] = max(dp[i][j-1],dp[i+1][j]); // max(prefix, suffix)
//                     }
//                 }
//             }
//         }
//         */
//         for(int i = n-1; i >= 0; i--){
//             dp[i][i] = 1;
//             for(int j = i+1; j < n; j++){
//                 if(s[i] == s[j]){
//                     dp[i][j] = dp[i+1][j-1]+2;
//                 } else {
//                     dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
//                 }
//             }
//         }
//         // ans is present in top right corner 
//         return dp[0][n-1];
//     }
// };