class Solution {
    public int minDistance(String word1, String word2) {
        int n = word1.length();
        int m = word2.length();
         // Create a table to store results of sub-problems
        int dp[][] = new int[n+1][m+1];

        // Fill lookup_table [][] in bottom up manner

        // If second string is empty, only option is to
        // remove all characters of first string
        for(int i = 0; i <= n; i++){
            dp[i][0] = i; // Min. operations = i
        }
        // If first string is empty, only option is to
        // insert all characters of second string
        for(int j = 0; j<= m; j++){
            dp[0][j] = j; // Min. operations = j
        }

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                // If last characters are same, ignore last char and recur for remaining string
                if(word1.charAt(i-1) == word2.charAt(j-1)){
                    dp[i][j] = dp[i-1][j-1];
                }else{
                    // If the last character is different, consider all possibilities and find the minimum
                    dp[i][j] = Math.min(dp[i - 1][j] + 1, Math.min(dp[i][j - 1] + 1, dp[i - 1][j - 1] + 1));
                }
            }
        }

        return dp[n][m];
    }
}

/* 
Base cases: Initialize the first row and first column of the DP array as follows:

dp[i][0] = i for all i from 0 to m, because converting word1[0:i] to an empty string requires i deletions.
dp[0][j] = j for all j from 0 to n, because converting an empty string to word2[0:j] requires j insertions.
Fill in the DP array: Traverse through the DP array and fill in the values for each cell based on the following conditions:

If word1[i-1] == word2[j-1], then dp[i][j] = dp[i-1][j-1], because no operation is needed to convert these characters.
Otherwise, dp[i][j] is the minimum of the following:
dp[i-1][j] + 1 (deletion): Convert word1[0:i-1] to word2[0:j] and delete word1[i-1].
dp[i][j-1] + 1 (insertion): Convert word1[0:i] to word2[0:j-1] and insert word2[j-1].
dp[i-1][j-1] + 1 (replacement): Convert word1[0:i-1] to word2[0:j-1] and replace word1[i-1] with word2[j-1].
Return the result: The minimum number of operations required to convert word1 to word2 is dp[m][n].
*/