class Solution {
public:
    int maxAns = 0;

    void dfs(vector<vector<int>>& grid, int n, int m, int i, int j, vector<vector<bool>>& visited, int& currentSum) {
        // Base condition: check for out-of-bounds, water cell (0), or already visited cell
        if (i < 0 || i >= n || j < 0 || j >= m || grid[i][j] == 0 || visited[i][j]) {
            return;
        }

        // Mark the current cell as visited
        visited[i][j] = true;

        // Add the current cell's value to the current connected component sum
        currentSum += grid[i][j];

        // Perform DFS in all four directions
        dfs(grid, n, m, i - 1, j, visited, currentSum);
        dfs(grid, n, m, i + 1, j, visited, currentSum);
        dfs(grid, n, m, i, j - 1, visited, currentSum);
        dfs(grid, n, m, i, j + 1, visited, currentSum);
    }

    int findMaxFish(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>> visited(n, vector<bool>(m, false));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                // If the cell has fish and hasn't been visited yet
                if (grid[i][j] != 0 && !visited[i][j]) {
                    int currentSum = 0;
                    dfs(grid, n, m, i, j, visited, currentSum);
                    maxAns = max(maxAns, currentSum);
                }
            }
        }

        return maxAns;
    }
};


/*
class Solution {
public:
    int dfs(vector<vector<int>>& grid, int n, int m, int i, int j, vector<vector<bool>>& visited) {
        // Boundary check and conditions to stop DFS
        if (i < 0 || i >= n || j < 0 || j >= m || grid[i][j] == 0 || visited[i][j]) {
            return 0;
        }

        // Mark the current cell as visited
        visited[i][j] = true;

        // Current cell's fish count
        int currFish = grid[i][j];

        // Explore all 4 directions and accumulate the fish count
        currFish += dfs(grid, n, m, i - 1, j, visited); // Up
        currFish += dfs(grid, n, m, i + 1, j, visited); // Down
        currFish += dfs(grid, n, m, i, j - 1, visited); // Left
        currFish += dfs(grid, n, m, i, j + 1, visited); // Right

        return currFish;
    }

    int findMaxFish(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int maxFish = 0;

        // Visited array to track visited cells
        vector<vector<bool>> visited(n, vector<bool>(m, false));

        // Iterate through the grid
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                // Start DFS only on unvisited cells with non-zero fish
                if (grid[i][j] != 0 && !visited[i][j]) {
                    // Find the fish count for the connected component
                    maxFish = max(maxFish, dfs(grid, n, m, i, j, visited));
                }
            }
        }

        return maxFish;
    }
};
*/




/*
class Solution {
public:
    int maxAns = 0;
    void dfs(vector<vector<int>>& grid, int n, int m, int i, int j,  vector<vector<bool>>& visited){
        if(i < 0 || i > n || j < 0 || j > m || grid[i][j] == 0 || visited[i][j] == true){
            return ;
        }
        visited[i][j] = true;

        int currVal = grid[i][j];

        maxAns += max(maxAns, maxAns+currVal);

        dfs(grid, n, m, i-1, j, visited);
        dfs(grid, n, m, i+1, j, visited);
        dfs(grid, n, m, i, j+1, visited);
        dfs(grid, n, m, i, j-1, visited);


    }

    int findMaxFish(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>> visited(n, vector<bool>(m,false));

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] != 0 && visited[i][j] == false){
                    dfs(grid, n, m, i, j, visited);
                }
            }
        }

        return maxAns;
    }
};
*/