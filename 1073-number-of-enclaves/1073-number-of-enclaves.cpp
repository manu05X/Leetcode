class Solution {
public:
    void dfs(vector<vector<int>>& grid, int n, int m, int currRow, int currCol) {
        // Base case: If the current cell is out of bounds or is not 1, return
        if (currRow < 0 || currRow >= n || currCol < 0 || currCol >= m || grid[currRow][currCol] != 1) {
            return;
        }

        // Mark the current cell as visited (2)
        grid[currRow][currCol] = 2;

        // Recursively visit all four neighboring cells (up, down, left, right)
        dfs(grid, n, m, currRow - 1, currCol); // up
        dfs(grid, n, m, currRow + 1, currCol); // down
        dfs(grid, n, m, currRow, currCol + 1); // right
        dfs(grid, n, m, currRow, currCol - 1); // left
    }

    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();    // Number of rows in the grid
        int m = grid[0].size(); // Number of columns in the grid

        // Step 1: Traverse the first and last columns
        for (int r = 0; r < n; r++) {
            // Check the first column
            if (grid[r][0] == 1) {
                dfs(grid, n, m, r, 0); // Mark all connected 1s as 2
            }
            // Check the last column
            if (grid[r][m - 1] == 1) {
                dfs(grid, n, m, r, m - 1); // Mark all connected 1s as 2
            }
        }

        // Step 2: Traverse the first and last rows
        for (int c = 0; c < m; c++) {
            // Check the first row
            if (grid[0][c] == 1) {
                dfs(grid, n, m, 0, c); // Mark all connected 1s as 2
            }
            // Check the last row
            if (grid[n - 1][c] == 1) {
                dfs(grid, n, m, n - 1, c); // Mark all connected 1s as 2
            }
        }

        // Step 3: Count the remaining 1s (enclaves)
        int enclaveCount = 0;
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < m; c++) {
                if (grid[r][c] == 1) {
                    enclaveCount++; // Count the number of 1s not connected to the boundary
                }
            }
        }

        return enclaveCount;
    }
};