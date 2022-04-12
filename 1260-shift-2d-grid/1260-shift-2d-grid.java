class Solution {
    public List<List<Integer>> shiftGrid(int[][] grid, int k) {
        int row = grid.length; // Number of rows in grid.
        int col = grid[0].length; // Number of columns in grid.
        
        int gridCount = row*col; // Number of cells (i.e. values) in grid.
        
        int[][] result = new int[row][col]; // Create result matrix, to hold shifted values.
        
        for(int i = 0; i < gridCount; i++){
            int ori_y = i / col;
            int ori_x = i % col;
            
            int new_y = (ori_y + (ori_x + k) / col) % row;
            int new_x = (ori_x + k) % col;
            
            result[new_y][new_x] = grid[ori_y][ori_x];
        }
        return (List)Arrays.asList(result);  
    }
}

/*
498 Diagonal Traverse
566 Reshape the Matrix
867 Transpose Matrix
*/