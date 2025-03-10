class Solution {
        public int numDistinct(String s, String t) {
        int m = s.length(); // Length of string `s`.
        int n = t.length(); // Length of string `t`.

        // Create a DP table of size (m+1) x (n+1) to store intermediate results.
        // dp[i][j] represents the number of distinct subsequences of t[j..n-1] in s[i..m-1].
        int[][] dp = new int[m + 1][n + 1];

        // Initialize all values in the DP table to 0.
        for (int[] row : dp) {
            Arrays.fill(row, 0);
        }

        // Base case: If `t` is empty (j == n), there is exactly 1 subsequence (empty string).
        // Fill the last column with 1s.
        for (int i = 0; i < m + 1; i++) {
            dp[i][n] = 1;
        }

        // Base case: If `s` is empty (i == m) and `t` is not empty (j < n), there are no subsequences.
        // Fill the last row with 0s.
        for (int j = 0; j < n; j++) {
            dp[m][j] = 0;
        }

        // Fill the DP table from bottom to top (i from m-1 to 0) and right to left (j from n-1 to 0).
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                // If the current characters of `s` and `t` match:
                if (s.charAt(i) == t.charAt(j)) {
                    // Case 1: Include the current character of `s` in the subsequence.
                    // Add the result from dp[i+1][j+1] (move both pointers forward).
                    // Case 2: Exclude the current character of `s` from the subsequence.
                    // Add the result from dp[i+1][j] (move only the pointer in `s` forward).
                    dp[i][j] += dp[i + 1][j + 1] + dp[i + 1][j];
                } else {
                    // If the current characters do not match:
                    // Exclude the current character of `s` from the subsequence.
                    // Add the result from dp[i+1][j] (move only the pointer in `s` forward).
                    dp[i][j] += dp[i + 1][j];
                }
            }
        }

        // The result is stored in dp[0][0], which represents the number of distinct subsequences
        // of `t` in the entire string `s`.
        return dp[0][0];
    }

}

/*
class Solution {
    // helper recursive function
    public int numberOfSubsequenceRec(String str1, String str2, int m, int n, int i1, int i2, int[][] lookupTable) {
        // if we have reached the end of str1, return 1
        if (i2 == n) {
            return 1;
        }

        // if we have reached the end of str2, return 0
        if (i1 == m) {
            return 0;
        }

        // if the result is not present in the lookup table
        if (lookupTable[i1][i2] == -1) {
            // if both the characters are same
            if (str1.charAt(i1) == str2.charAt(i2)) {
                lookupTable[i1][i2] = numberOfSubsequenceRec(str1, str2, m, n, i1 + 1, i2 + 1, lookupTable);
                lookupTable[i1][i2] += numberOfSubsequenceRec(str1, str2, m, n, i1 + 1, i2, lookupTable);    // ignoring this match
            } else {
                // if both the characters are different
                lookupTable[i1][i2] = numberOfSubsequenceRec(str1, str2, m, n, i1 + 1, i2, lookupTable);
            }
        }

        // return the result stored in the lookup table
        return lookupTable[i1][i2];
    }
     
    public int numDistinct(String s, String t) {
        int m = s.length(); // Length of string `s`.
        int n = t.length(); // Length of string `t`.

        // initializing lookup table to store the results of recursive calls
        int[][] lookupTable = new int[m][n];
        for(int[] row: lookupTable){
            Arrays.fill(row, -1);
        }

        // Call the recursive helper function starting from indices 0 in both `s` and `t`.
        int numSubsequence = numberOfSubsequenceRec(s, t, m, n, 0, 0, lookupTable);

        return numSubsequence;
    }
}

*/

/*
class Solution {
    
    //  * Recursive helper function to count the number of distinct subsequences of `t` in `s`.
    //  *
    //  * @param s   The input string `s`.
    //  * @param t   The target string `t`.
    //  * @param m   The length of string `s`.
    //  * @param n   The length of string `t`.
    //  * @param i1  Current index in string `s`.
    //  * @param i2  Current index in string `t`.
    //  * @return    The number of distinct subsequences of `t` in `s` starting from indices `i1` and `i2`.
     
    public int numberOfSubsequenceRec(String s, String t, int m, int n, int i1, int i2) {
        // Base case: If we have matched all characters of `t`, return 1 (valid subsequence found).
        if (i2 == n) {
            return 1;
        }

        // Base case: If we have exhausted all characters of `s`, return 0 (no valid subsequence).
        if (i1 == m) {
            return 0;
        }

        int ans = 0;

        // If the current characters of `s` and `t` match:
        if (s.charAt(i1) == t.charAt(i2)) {
            // Case 1: Include the current character of `s` in the subsequence.
            // Move both pointers forward in `s` and `t`.
            ans += numberOfSubsequenceRec(s, t, m, n, i1 + 1, i2 + 1);

            // Case 2: Exclude the current character of `s` from the subsequence.
            // Move only the pointer in `s` forward.
            ans += numberOfSubsequenceRec(s, t, m, n, i1 + 1, i2);
        } else {
            // If the current characters do not match:
            // Exclude the current character of `s` from the subsequence.
            // Move only the pointer in `s` forward.
            ans += numberOfSubsequenceRec(s, t, m, n, i1 + 1, i2);
        }

        return ans;
    }

    
    //  * Main function to count the number of distinct subsequences of `t` in `s`.
    //  *
    //  * @param s The input string `s`.
    //  * @param t The target string `t`.
    //  * @return  The number of distinct subsequences of `t` in `s`.
     
    public int numDistinct(String s, String t) {
        int m = s.length(); // Length of string `s`.
        int n = t.length(); // Length of string `t`.

        // Call the recursive helper function starting from indices 0 in both `s` and `t`.
        int numSubsequence = numberOfSubsequenceRec(s, t, m, n, 0, 0);

        return numSubsequence;
    }
}
*/