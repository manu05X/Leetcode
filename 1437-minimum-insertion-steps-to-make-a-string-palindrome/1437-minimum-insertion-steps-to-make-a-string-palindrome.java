class Solution {
    public int minInsertions(String s) {
        int n = s.length();

        String revS = new StringBuilder(s).reverse().toString();

        int lps = longestCommonSubsequence(s, revS);

        return n - lps;
    }

    public int longestCommonSubsequence(String s1, String s2){
        int n = s1.length();
        int[][] dp = new int[n+1][n+1];

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(s1.charAt(i-1) == s2.charAt(j-1)){
                    dp[i][j] = dp[i-1][j-1]+1;
                } else {
                     dp[i][j] = Math.max(dp[i][j-1], dp[i-1][j]);
                }
            }
        }

        return dp[n][n];
    }
}