class Solution {
    public void dfs(char[][] grid, int r, int c){
        int nR = grid.length;
        int nC = grid[0].length;
        
        if(r<0 || c<0 || r >= nR || c >= nC || grid[r][c] == '0'){
            return;
        }
        grid[r][c] = '0';
        dfs(grid, r - 1, c);
        dfs(grid, r + 1, c);
        dfs(grid, r, c - 1);
        dfs(grid, r, c + 1);
    }
    public int numIslands(char[][] grid) {
        if(grid == null || grid.length == 0)
            return 0;
        
        int nR = grid.length;
        int nC = grid[0].length;
        
        int count = 0;
        
        for(int r = 0; r < nR; r++)
        {
            for(int c = 0; c < nC; c++)
            {
                if(grid[r][c] == '1')
                {
                    count++;
                    dfs(grid,r,c);
                }
            }
        }
        return count;
    }
}