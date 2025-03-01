class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        // Get the number of rows and columns in the grid
        int row = grid.size();
        int col = grid[0].size();

        // Create a 2D DP vector initialized with 0
        vector<vector<int>> dp(row, vector<int>(col, 0));

        // Initialize the starting point (top-left corner)
        dp[0][0] = grid[0][0];

        // Fill the first row: The only way to reach each cell is from the left
        for(int i = 1; i < col; i++){
            dp[0][i] = dp[0][i-1] + grid[0][i];
        }

        // Fill the first column: The only way to reach each cell is from above
        for(int i = 1; i < row; i++){
            dp[i][0] = dp[i-1][0] + grid[i][0];
        }

        // Fill the rest of the DP table using the recurrence relation:
        // The minimum path sum to reach (i, j) is the current grid value + 
        // the minimum path sum from either the top (i-1, j) or left (i, j-1)
        for(int i = 1; i < row; i++){
            for(int j = 1; j < col; j++){
                // Calculate the minimum path sum for the current cell by adding the current grid value to the minimum of the top and left cells in the dp vector
                dp[i][j] = grid[i][j] + min(dp[i-1][j], dp[i][j-1]);
            }
        }

        // Return the minimum path sum for reaching the bottom-right corner
        return dp[row-1][col-1];
    }
};
