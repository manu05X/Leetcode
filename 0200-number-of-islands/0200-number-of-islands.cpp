class Solution {
public:
    int n, m; // Global variables to store matrix dimensions

    // Depth-First Search (DFS) function to mark connected land ('1') as visited
    void dfs(vector<vector<char>>& grid, int row, int col){
        // Base condition: Stop if out of bounds or water ('0') or already visited ('x')
        if(row >= n || row < 0 || col >= m || col < 0 || grid[row][col] != '1'){
            return;
        }
        
        // Mark the current land cell as visited
        grid[row][col] = 'x';
        
        // Recursive calls to explore all four directions
        dfs(grid, row+1, col); // Down
        dfs(grid, row-1, col); // Up
        dfs(grid, row, col+1); // Right
        dfs(grid, row, col-1); // Left
    }

    // Function to count the number of islands
    int numIslands(vector<vector<char>>& grid) {
        n = grid.size();    // Get number of rows
        m = grid[0].size(); // Get number of columns
        
        int count = 0; // Variable to count the number of islands
        
        // Traverse the entire grid
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                // If we find an unvisited land cell ('1')
                if(grid[i][j] == '1')
                {
                    count++; // Increment the island count
                    dfs(grid, i, j); // Perform DFS to mark the entire island
                }
            }
        }
        
        return count; // Return the total number of islands
    }
};
