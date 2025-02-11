class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(); // Number of rows
        int m = grid[0].size(); // Number of columns

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 2){
                    dfs(grid, i, j, 2);
                }
            }
        }

        int ans = 2;
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1){
                    return -1;
                }

                ans = max(ans, grid[i][j]);
            }
        }

        return ans-2;
    }


    void dfs(vector<vector<int>>& grid, int row, int col, int minutes){
        int n = grid.size(); // Number of rows
        int m = grid[0].size(); // Number of columns

        if(row < 0 || row >= n || col < 0 || col >= m || grid[row][col] == 0 || (grid[row][col] > 1 && grid[row][col] < minutes)){
            return ;
        }

        grid[row][col] = minutes;
        // Explore all 4 directions
        dfs(grid, row - 1, col, minutes + 1); // Up
        dfs(grid, row + 1, col, minutes + 1); // Down
        dfs(grid, row, col - 1, minutes + 1); // Left
        dfs(grid, row, col + 1, minutes + 1); // Right

    }

};



/*
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(); // Number of rows
        int m = grid[0].size(); // Number of columns

        // Traverse the grid to find all initially rotten oranges
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    // Start DFS from each rotten orange
                    dfs(grid, i, j, 2);
                }
            }
        }

        int minutes = 2; // To track the time taken for rotting process

        // Check if any fresh oranges remain and get the maximum time taken
        for (const auto& row : grid) {
            for (int cell : row) {
                if (cell == 1) return -1; // Fresh orange remains -> not all oranges rot
                minutes = max(minutes, cell); // Track maximum value in the grid
            }
        }

        return minutes - 2; // Subtract 2 to adjust for initial rotten oranges
    }

private:
    void dfs(vector<vector<int>>& grid, int row, int col, int minutes) {
        int n = grid.size(), m = grid[0].size();

        // Boundary conditions
        if (row < 0 || row >= n || col < 0 || col >= m || grid[row][col] == 0 ||
            (grid[row][col] > 1 && grid[row][col] < minutes)) {
            return;
        }

        grid[row][col] = minutes; // Mark the orange with the current time

        // Explore all 4 directions
        dfs(grid, row - 1, col, minutes + 1); // Up
        dfs(grid, row + 1, col, minutes + 1); // Down
        dfs(grid, row, col - 1, minutes + 1); // Left
        dfs(grid, row, col + 1, minutes + 1); // Right
    }
};
*/


/*
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();

        vector<vector<int>> visited = grid;

        queue<pair<int, int>> q;
        int countFreshOranges = 0;
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                if(visited[i][j] == 2)
                {
                    q.push({i,j});
                }
                if(visited[i][j] == 1){
                    countFreshOranges++;
                }
            }
        }
        if(countFreshOranges == 0)
            return 0;
        if(q.empty())
            return -1;
        
        int minutes = -1;
        // we will cover four directions i.e. up, down, left, right
        vector<pair<int, int>> dirs = {{1, 0},{-1, 0},{0, -1},{0, 1}};
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                auto [x,y] = q.front();
                q.pop();
                for(auto [dx,dy]: dirs){
                    int i = x+dx;
                    int j = y+dy;
                    if (i >= 0 && i < r && j >= 0 && j < c && visited[i][j] == 1) {
                        visited[i][j] = 2;
                        countFreshOranges--;
                        q.push({i, j});
                    }
                }
            }
            minutes++;
        }
        if(countFreshOranges == 0)
            return minutes;
        return -1;
    }
};
*/