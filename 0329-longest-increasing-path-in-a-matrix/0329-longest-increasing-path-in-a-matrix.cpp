class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        // Initialize a DP table to store the length of the longest path for each cell
        vector<vector<int>> dp(n, vector<int>(m, -1));

        // Lambda function for the DFS helper
        auto dfs = [&](auto&& dfs, int i, int j, int prevValue) -> int {
            // Base cases: boundary check and increasing path condition
            if (i < 0 || i >= n || j < 0 || j >= m || matrix[i][j] <= prevValue) {
                return 0;
            }

            // Return memoized value if the cell has already been processed
            if (dp[i][j] != -1) {
                return dp[i][j];
            }

            int currentValue = matrix[i][j];

            // Explore all four directions
            int down = dfs(dfs, i + 1, j, currentValue);
            int up = dfs(dfs, i - 1, j, currentValue);
            int right = dfs(dfs, i, j + 1, currentValue);
            int left = dfs(dfs, i, j - 1, currentValue);

            // Calculate the longest path from the current cell
            dp[i][j] = 1 + max(max(down, up), max(left, right));

            return dp[i][j];
        };

        int maxLength = 0; // Variable to track the maximum path length

        // Iterate over all cells and calculate the longest increasing path
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                maxLength = max(maxLength, dfs(dfs, i, j, INT_MIN));
            }
        }

        return maxLength; // Return the maximum path length
    }
};



/*
class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size(); // Number of rows in the matrix
        int m = matrix[0].size(); // Number of columns in the matrix

        // DP table to store the length of the longest path starting from each cell
        vector<vector<int>> dp(n, vector<int>(m, -1));

        int maxLength = 0; // To store the maximum length of increasing path in the matrix

        // Iterate through each cell of the matrix
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                // Compute the longest increasing path starting from cell (i, j)
                maxLength = max(maxLength, dfs(matrix, dp, i, j, n, m, INT_MIN));
            }
        }

        return maxLength; // Return the maximum path length found
    }

    // DFS function to calculate the longest increasing path from a cell
    int dfs(vector<vector<int>>& matrix, vector<vector<int>>& dp, int i, int j, int n, int m, int preValue) {
        // If the cell is out of bounds or the current cell value is not greater than the previous cell value
        if (i < 0 || i >= n || j < 0 || j >= m || matrix[i][j] <= preValue) {
            return 0;
        }

        // If the result for this cell is already calculated, return the stored value
        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        int currCellValue = matrix[i][j]; // Store the current cell's value

        matrix[i][j] = -1; // Mark the cell as visited to avoid revisiting during the same DFS path

        int maxPath = 0; // To store the maximum path length from the current cell

        // Explore the four possible directions (down, up, right, left) recursively
        int down = dfs(matrix, dp, i + 1, j, n, m, currCellValue);
        int up = dfs(matrix, dp, i - 1, j, n, m, currCellValue);
        int right = dfs(matrix, dp, i, j + 1, n, m, currCellValue);
        int left = dfs(matrix, dp, i, j - 1, n, m, currCellValue);

        // Include the current cell in the path and update the maximum path length
        maxPath = 1 + max(max(down, up), max(left, right));

        matrix[i][j] = currCellValue; // Restore the cell's value after the DFS call

        dp[i][j] = maxPath; // Store the computed result in the DP table for future reference

        return maxPath; // Return the computed maximum path length for the current cell
    }
};

*/