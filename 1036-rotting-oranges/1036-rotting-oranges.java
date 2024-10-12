class Solution {
    public int orangesRotting(int[][] grid) {
        int n = grid.length; // Get the number of rows in the grid

        // Traverse the grid to find all initially rotten oranges
        for(int i = 0; i < n; i++){
            for(int j = 0; j < grid[0].length; j++){
                // If we find a rotten orange (value 2)
                if(grid[i][j] == 2){
                    // Start a DFS from this rotten orange to spread the rot
                    dfs(grid, i, j, 2);
                }
            }
        }

        int minutes = 2; // Initialize minutes to track the time taken for the rot to spread

        // Check the grid for any fresh oranges and determine the maximum time taken
        for(int[] row : grid){
            for(int cell : row){
                // If any fresh orange (value 1) remains, return -1 (not all can rot)
                if(cell == 1){
                    return -1;
                }

                // Update the maximum minutes taken to rot oranges
                minutes = Math.max(minutes, cell);
            }
        }

        // Return the total minutes taken minus the initial value (2)
        // because the initial rotten oranges are counted as minute 2
        return minutes - 2;
    }

    private void dfs(int[][] grid, int row, int col, int minutes){
        // Check for out-of-bounds conditions
        if(row < 0 || row >= grid.length || // Check if row is out of bounds
            col < 0 || col >= grid[0].length || // Check if column is out of bounds
            grid[row][col] == 0 || // Check if the cell is empty (0)
            (1 < grid[row][col] && grid[row][col] < minutes)) // Check if this orange is already rotten by another orange
        {
            return; // Exit if any condition is met
        }
        else {
            // Mark the current cell with the current minutes count
            grid[row][col] = minutes; 
            // Continue the DFS in all four directions to spread the rot
            dfs(grid, row - 1, col, minutes + 1); // Up
            dfs(grid, row + 1, col, minutes + 1); // Down
            dfs(grid, row, col - 1, minutes + 1); // Left
            dfs(grid, row, col + 1, minutes + 1); // Right
        }
    }
}
