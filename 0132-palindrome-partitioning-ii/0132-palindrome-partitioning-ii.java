class Solution {
    public int minCut(String s) {
        int n = s.length();
        int[] dp = new int[n];
        boolean[][] isPalin = new boolean[n][n];
        
        for (int i = 0; i < n; i++) 
        {
            int minCuts = i; // maximum cuts required is i (cut each character)
            for (int j = 0; j <= i; j++) 
            {
                if (s.charAt(j) == s.charAt(i) && (i - j <= 2 || isPalin[j + 1][i - 1])) 
                {
                    isPalin[j][i] = true;
                    minCuts = (j == 0) ? 0 : Math.min(minCuts, dp[j - 1] + 1);
                }
            }
            dp[i] = minCuts;
        }
        return dp[n - 1];
    }
}
