class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int n = dungeon.size();
        int m = dungeon[0].size();

        vector<vector<int>> dp(n, vector<int>(m, 0));

        // Base Case: Minimum health needed at the bottom-right corner
        dp[n-1][m-1] = max(1, 1 - dungeon[n-1][m-1]);

        // Fill last row (only moving left)
        for (int j = m - 2; j >= 0; j--) {
            dp[n-1][j] = max(1, dp[n-1][j+1] - dungeon[n-1][j]);
        }

        // Fill last column (only moving up)
        for (int i = n - 2; i >= 0; i--) {
            dp[i][m-1] = max(1, dp[i+1][m-1] - dungeon[i][m-1]);
        }

        // Fill the rest of the DP table
        for (int i = n - 2; i >= 0; i--) {
            for (int j = m - 2; j >= 0; j--) {
                int min_health_needed = min(dp[i+1][j], dp[i][j+1]) - dungeon[i][j];
                dp[i][j] = max(1, min_health_needed);
            }
        }

        return dp[0][0]; // Minimum initial health needed
    }
};


/*

[-2,-3,3]
[-5,-10,1]
[10,30,-5]

dp = [
  [0, 0, 0],
  [0, 0, 0],
  [0, 0, 0]
]

row = 2
dp = [
  [0, 0, 0],
  [0, 0, 0],
  [1, 1, 6]
]

row = 1
dp = [
  [0, 0, 0],
  [6, 11, 5],
  [1, 1, 6]
0

row=1
dp = [
  [7, 5, 2],
  [6, 11, 5],
  [1, 1, 6]
]

*/