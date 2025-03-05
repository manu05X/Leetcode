class Solution {
public:
    // DFS function to mark all connected '1's as visited ('0')
    void dfs(vector<vector<char>>& grid, int i, int j) {
        int n = grid.size();
        int m = grid[0].size();

        // Base case: If the current cell is out of bounds or is not '1', return
        if (i < 0 || i >= n || j < 0 || j >= m || grid[i][j] != '1') {
            return;
        }

        // Mark the current cell as visited ('0')
        grid[i][j] = '0';

        // Recursively visit all four neighboring cells (up, down, left, right)
        dfs(grid, i - 1, j); // up
        dfs(grid, i + 1, j); // down
        dfs(grid, i, j - 1); // left
        dfs(grid, i, j + 1); // right
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int islandCount = 0; // Initialize the island count

        // Traverse the entire grid
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1') {
                    // Perform DFS to mark all connected '1's as visited ('0')
                    dfs(grid, i, j);
                    islandCount++; // Increment the island count
                }
            }
        }

        return islandCount;
    }
};

/*

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

*/
