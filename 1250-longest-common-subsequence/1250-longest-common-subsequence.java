//Revision
class Solution {
    public int longestCommonSubsequence(String text1, String text2) {
       int n = text1.length();
        int m = text2.length();

        int dp[][] = new int[n+1][m+1];
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(text1.charAt(i-1) == text2.charAt(j-1))
                {
                    dp[i][j] = dp[i-1][j-1] + 1;
                }
                else{
                    dp[i][j] = Math.max(dp[i][j-1], dp[i-1][j]);
                }
            }
        }

        return dp[n][m];  
    }
}


/*
class Solution {
    // Helper function with updated signature: i is current index in str1, j is current index in str2
  public static int longestCommonSubsequenceHelper(String str1, String str2, int i, int j, int[][] dp){
        // base case
        if (i == str1.length() || j == str2.length()) 
            return 0;

        // if the subproblem has been computed before, return the value stored in M
        else if (dp[i][j] != -1) 
            return dp[i][j];

        // if current characters match, increment 1
        else if (str1.charAt(i) == str2.charAt(j)){
        dp[i][j] = 1 + longestCommonSubsequenceHelper(str1, str2, i + 1, j + 1, dp);
        return dp[i][j];
        }

        // else take max of either of two possibilities
        dp[i][j] = Math.max(longestCommonSubsequenceHelper(str1, str2, i + 1, j, dp),
                        longestCommonSubsequenceHelper(str1, str2, i, j + 1, dp));
        return dp[i][j];
  }

    public int longestCommonSubsequence(String str1, String str2) {
        int rows = str1.length();
        int cols = str2.length();

        int[][] dp = new int[rows][cols];

        for (int i = 0; i < rows; i++) { 
            for (int j = 0; j < cols; j++) { 
                dp[i][j] = -1; 
            } 
        }
        return longestCommonSubsequenceHelper(str1, str2, 0, 0, dp);
    }
}
*/


/*
class Solution {
    // Helper function with updated signature: i is current index in str1, j is current index in str2
  public static int longestCommonSubsequenceHelper(String str1, String str2, int i, int j){
      // base case
      if (i == str1.length() || j == str2.length()) 
          return 0;

      // if current characters match, increment 1
      else if (str1.charAt(i) == str2.charAt(j)) 
          return 1 + longestCommonSubsequenceHelper(str1, str2, i+1, j+1);
      
      // else take max of either of two possibilities
      return Math.max(longestCommonSubsequenceHelper(str1, str2, i+1, j), longestCommonSubsequenceHelper(str1, str2, i, j+1));
  }
    public int longestCommonSubsequence(String text1, String text2) {
        return longestCommonSubsequenceHelper(text1, text2, 0, 0);
    }
}
*/

