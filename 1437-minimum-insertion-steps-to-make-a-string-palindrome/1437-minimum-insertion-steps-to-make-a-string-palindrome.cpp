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