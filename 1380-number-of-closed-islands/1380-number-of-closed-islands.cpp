class Solution {
public:
    // DFS function to mark all connected 0s as visited (1)
    void dfs(vector<vector<int>>& grid, int i, int j) {
        int n = grid.size();
        int m = grid[0].size();

        // Base case: If the current cell is out of bounds or is not 0, return
        if (i < 0 || i >= n || j < 0 || j >= m || grid[i][j] != 0) {
            return;
        }

        // Mark the current cell as visited (1)
        grid[i][j] = 1;

        // Recursively visit all four neighboring cells (up, down, left, right)
        dfs(grid, i - 1, j); // up
        dfs(grid, i + 1, j); // down
        dfs(grid, i, j - 1); // left
        dfs(grid, i, j + 1); // right
    }

    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        // Step 1: Traverse the boundary and mark all connected 0s as visited (1)
        for (int i = 0; i < n; i++) {
            // Check the first column
            if (grid[i][0] == 0) {
                dfs(grid, i, 0);
            }
            // Check the last column
            if (grid[i][m - 1] == 0) {
                dfs(grid, i, m - 1);
            }
        }

        for (int j = 0; j < m; j++) {
            // Check the first row
            if (grid[0][j] == 0) {
                dfs(grid, 0, j);
            }
            // Check the last row
            if (grid[n - 1][j] == 0) {
                dfs(grid, n - 1, j);
            }
        }

        // Step 2: Count the number of closed islands
        int closedIslandCount = 0;
        for (int i = 1; i < n - 1; i++) {
            for (int j = 1; j < m - 1; j++) {
                if (grid[i][j] == 0) {
                    // Perform DFS to mark all connected 0s as visited (1)
                    dfs(grid, i, j);
                    closedIslandCount++; // Increment the count of closed islands
                }
            }
        }

        return closedIslandCount;
    }
};


/*
class Solution {
public:
    int count = 0;  // Variable to store the number of closed islands
    int n = 0;  // Number of rows
    int m = 0;  // Number of columns

    int closedIsland(vector<vector<int>>& grid) {
        ios_base::sync_with_stdio(false);  
        cin.tie(NULL);

        n = grid.size();
        m = grid[0].size();

        // Traverse the boundary and mark any island touching the boundary as open
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if ((i == 0 || i == n - 1 || j == 0 || j == m - 1) && grid[i][j] == 0) {
                    dfs(i, j, grid);  // Mark the boundary island as visited
                }
            }
        }

        // Now count the closed islands
        for (int i = 1; i < n - 1; i++) {
            for (int j = 1; j < m - 1; j++) {
                if (grid[i][j] == 0) {
                    dfs(i, j, grid);  // Mark the closed island as visited
                    count++;  // Increment the closed island count
                }
            }
        }

        return count;
    }

    // DFS to mark the island (land = 0) as visited (change to 1)
    void dfs(int r, int c, vector<vector<int>>& grid) {
        // Boundary or water (grid[r][c] == 1), return immediately
        if (r < 0 || r >= n || c < 0 || c >= m || grid[r][c] == 1) {
            return;
        }

        // Mark the current cell as visited by setting it to 1
        grid[r][c] = 1;

        // Move in all 4 possible directions
        dfs(r - 1, c, grid);  // Up
        dfs(r + 1, c, grid);  // Down
        dfs(r, c - 1, grid);  // Left
        dfs(r, c + 1, grid);  // Right
    }
};

*/

/*
[1,1,1,1,1,1,1,0],
[1,0,0,0,0,1,1,0],
[1,0,1,0,1,1,1,0],
[1,0,0,0,0,1,0,1],
[1,1,1,1,1,1,1,0]
*/