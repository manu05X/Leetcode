
//bfs
class Solution {
    // Function to find minimum time required to rot all oranges. 
    public int orangesRotting(int[][] grid) {
        int n = grid.length;
        int m = grid[0].length;

        // Queue to store rotten oranges' positions
        Queue<Pair<Integer, Integer>> q = new LinkedList<>();
        int countFresh = 0; // Count of fresh oranges

        // Initialize the queue with all rotten oranges
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    q.add(new Pair<>(i, j)); // Enqueue rotten orange coordinates
                } else if (grid[i][j] == 1) {
                    countFresh++; // Count fresh oranges
                }
            }
        }

        // If there are no fresh oranges, return 0 (nothing to rot)
        if (countFresh == 0) {
            return 0;
        }

        // Directions for up, down, left, right
        int[] dx = {1, -1, 0, 0};
        int[] dy = {0, 0, 1, -1};

        int minutes = -1; // Time counter for rotting process

        // Perform BFS to rot adjacent fresh oranges
        while (!q.isEmpty()) {
            int size = q.size();
            minutes++; // Each level of BFS represents 1 minute

            // Process all rotten oranges at the current minute
            for (int i = 0; i < size; i++) {
                Pair<Integer, Integer> temp = q.poll();
                int x = temp.getKey();
                int y = temp.getValue();

                // Try to rot adjacent fresh oranges in all 4 directions
                for (int k = 0; k < 4; k++) {
                    int newX = x + dx[k];
                    int newY = y + dy[k];

                    // Check if the new coordinates are within bounds and contain a fresh orange
                    if (newX >= 0 && newX < n && newY >= 0 && newY < m && grid[newX][newY] == 1) {
                        grid[newX][newY] = 2; // Mark the orange as rotten
                        countFresh--; // Decrease the count of fresh oranges
                        q.add(new Pair<>(newX, newY)); // Enqueue the newly rotten orange
                    }
                }
            }
        }

        // If there are no fresh oranges left, return the minutes taken to rot all oranges
        if (countFresh == 0) {
            return minutes;
        }

        // If there are still fresh oranges that can't be rotted, return -1
        return -1;
    }
}

// Helper class to store a pair of integers (coordinates)
class Pair<K, V> {
    private K key;
    private V value;

    public Pair(K key, V value) {
        this.key = key;
        this.value = value;
    }

    public K getKey() {
        return key;
    }

    public V getValue() {
        return value;
    }
}

/*
//dfs
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
*/