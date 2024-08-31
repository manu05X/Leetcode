class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();

        vector<vector<int>> dp(row, vector<int>(col,0));

        dp[0][0] = grid[0][0];
        for(int i = 1; i < col; i++){
            dp[0][i] = dp[0][i-1]+grid[0][i];
        }

        for(int i = 1; i < row; i++){
            dp[i][0] = dp[i-1][0]+grid[i][0];
        }

        for(int i = 1; i < row; i++){
            for(int j = 1; j < col; j++){
                // Calculate the minimum path sum for the current cell by adding the current grid value to the minimum of the top and left cells in the dp vector
                dp[i][j] = grid[i][j]+ min(dp[i-1][j], dp[i][j-1]);
            }
        }
         // Return the minimum path sum for the bottom-right corner of the grid
        return dp[row-1][col-1];

    }
};