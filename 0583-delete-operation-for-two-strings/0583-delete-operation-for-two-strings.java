class Solution {
    public int minDistance(String word1, String word2) {
        int m = word1.length();
        int n = word2.length();

        // Create a DP table where dp[i][j] represents the LCS of word1[0...i-1] and word2[0...j-1]
        int[][] dp = new int[m + 1][n + 1];

        // Fill the DP table
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (word1.charAt(i - 1) == word2.charAt(j - 1)) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = Math.max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        int lcsLength = dp[m][n]; // Longest Common Subsequence (LCS)

        // Minimum deletions = (total length of both strings) - (twice the LCS length)
        return (m - lcsLength) + (n - lcsLength);
    }
}

/*
public class Solution {
    public int minDistance(String s1, String s2) {
        int m = s1.length();
        int n = s2.length();

        // Find the longest common subsequence (LCS)
        int lcsLength = lcs(s1, s2, m, n);
        
        // The minimum steps to make the two strings the same is (total length of both strings) - (twice the LCS length)
        return (m - lcsLength) + (n - lcsLength);
        // return s1.length() + s2.length() - 2 * lcs(s1, s2, s1.length(), s2.length());
    }
    public int lcs(String s1, String s2, int m, int n) {
        int[][] dp = new int[m + 1][n + 1];

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (s1.charAt(i - 1) == s2.charAt(j - 1)) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = Math.max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[m][n];
    }
}
*/

/*
public class Solution {
    public int minDistance(String s1, String s2) {
        int m = s1.length();
        int n = s2.length();

        // Find the longest common subsequence (LCS)
        int lcsLength = lcs(s1, s2, m, n);
        
        // The minimum steps to make the two strings the same is (total length of both strings) - (twice the LCS length)
        return (m - lcsLength) + (n - lcsLength);
        // return s1.length() + s2.length() - 2 * lcs(s1, s2, s1.length(), s2.length());
    }
    public int lcs(String s1, String s2, int m, int n) {
        if (m == 0 || n == 0)
            return 0;
        if (s1.charAt(m - 1) == s2.charAt(n - 1))
            return 1 + lcs(s1, s2, m - 1, n - 1);
        else
            return Math.max(lcs(s1, s2, m, n - 1), lcs(s1, s2, m - 1, n));
    }
}

*/
