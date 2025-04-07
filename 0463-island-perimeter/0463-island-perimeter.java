class Solution {
    public int islandPerimeter(int[][] grid) {
        int rows = grid.length, cols = grid[0].length;
        int perimeter = 0;
        
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (grid[r][c] == 1) {
                    perimeter += 4; // Each land cell initially has 4 sides
                    
                    // Check bottom neighbor
                    if (r < rows - 1 && grid[r + 1][c] == 1) {
                        perimeter -= 2; // Shared edge reduces 2
                    }
                    
                    // Check right neighbor
                    if (c < cols - 1 && grid[r][c + 1] == 1) {
                        perimeter -= 2; // Shared edge reduces 2
                    }
                }
            }
        }
        return perimeter;
    }
}