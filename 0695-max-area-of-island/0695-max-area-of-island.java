class Solution {

    // Directions arrays for 8 possible moves (left, right, up, down, and 4 diagonal moves).
    int[] rowDir = {1, -1, 0, 0};
    int[] colDir = {0, 0, 1, -1};

    public int maxAreaOfIsland(int[][] grid) {
        int max_area = 0;
        int n = grid.length;
        int m = grid[0].length;

        // Traverse the entire grid
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                // If we find a 1, initiate BFS to find the area of the region.
                if (grid[i][j] == 1)
                {
                    int area = bfs(grid, i, j, n, m);
                    max_area = Math.max(max_area, area); // Track the maximum area found.
                }
            }
        }
        return max_area;
    }

    // BFS function to explore the grid in 8 directions and calculate the area of the region.
    public int bfs(int[][] grid, int row, int col, int n, int m)
    {
        // Initialize a queue for BFS.
        Queue<int[]> queue = new LinkedList<>();
        queue.add(new int[]{row, col});
        
        // Mark the starting cell as visited by setting it to 0.
        grid[row][col] = 0;
        
        // Initialize the area of the current region as 1 (starting with the current cell).
        int area = 1;
        
        // Perform BFS.
        while (!queue.isEmpty())
        {
            // Get the current cell's coordinates.
            int[] cell = queue.poll();
            int currRow = cell[0];
            int currCol = cell[1];
            
            // Explore all 8 directions from the current cell.
            for (int i = 0; i < 4; i++)
            {
                int newRow = currRow + rowDir[i];
                int newCol = currCol + colDir[i];
                
                // Check if the new position is valid and contains a 1.
                if (isValid(grid, newRow, newCol, n, m))
                {
                    // Mark the cell as visited by setting it to 0.
                    grid[newRow][newCol] = 0;
                    // Add the cell to the queue for further exploration.
                    queue.add(new int[]{newRow, newCol});
                    // Increase the area of the region.
                    area++;
                }
            }
        }
        
        return area;
    }

    // Helper function to check if a cell is within the bounds of the grid and contains a 1.
    public boolean isValid(int[][] grid, int row, int col, int n, int m)
    {
        return (row >= 0 && row < n && col >= 0 && col < m && grid[row][col] == 1);
    }
}