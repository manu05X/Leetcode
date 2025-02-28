class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();   // Number of rows
        int m = grid[0].size(); // Number of columns

        queue<pair<pair<int, int>, int>> q;  // Queue to store {row, column, time}
        vector<vector<bool>> visited(n,vector<bool>(m, false)); // Visited array to track processed cells
        int cntFresh = 0; // Count of fresh oranges

        // Step 1: Initialize the queue with all rotten oranges and count fresh oranges
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 2){ // If the cell has a rotten orange
                    q.push({{i,j}, 0});  // Push position with time 0
                    visited[i][j] = true; // Mark as visited
                }

                if(grid[i][j] == 1){ // Count fresh oranges
                    cntFresh++;
                }
            }
        }

        int tm = 0; // Variable to track the maximum time required
        int dRow[] = {-1, 0, +1, 0}; // Row movement (Up, Right, Down, Left)
        int dCol[] = {0, +1, 0, -1}; // Column movement (Up, Right, Down, Left)
        int count = 0; // Counter for the number of fresh oranges that get rotten

        // Step 2: Process the queue using BFS
        while(!q.empty()){
            int r = q.front().first.first;  // Current row
            int c = q.front().first.second; // Current column
            int t = q.front().second;       // Current time step

            tm = max(t, tm); // Update max time required
            q.pop(); // Remove processed node from queue

            // Step 3: Check all 4 possible adjacent cells
            for(int i = 0; i < 4; i++){
                int nr = r + dRow[i]; // New row index
                int nc = c + dCol[i]; // New column index

                // Check if the new cell is within bounds and is a fresh orange
                if(nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == 1 && visited[nr][nc] == false){
                    q.push({{nr,nc}, t+1}); // Push the new rotten orange into queue
                    visited[nr][nc] = true; // Mark as visited
                    count++; // Increase the count of rotted fresh oranges
                }
            }
        }

        // Step 4: If all fresh oranges are not rotted, return -1
        if(count != cntFresh){
            return -1;
        }

        // Step 5: Return the time required to rot all oranges
        return tm;
    }
};




/*
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

*/

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