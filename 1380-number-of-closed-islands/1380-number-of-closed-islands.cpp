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

/*
[1,1,1,1,1,1,1,0],
[1,0,0,0,0,1,1,0],
[1,0,1,0,1,1,1,0],
[1,0,0,0,0,1,0,1],
[1,1,1,1,1,1,1,0]
*/