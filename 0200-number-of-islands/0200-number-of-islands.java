class Solution {
    public int numIslands(char[][] grid) {
        int m = grid.length;
        int n = grid[0].length;

        if(n == 0 || m==0){
            return 0;
        }
        int count = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == '1'){
                    count++;
                    dfs(grid, m, n, i, j);
                }
            }
        }
        return count;
    }

    public void dfs(char[][] grid, int m, int n, int i, int j){
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] != '1') 
        {
            return;
        }
        grid[i][j] = 'X';
        dfs(grid, m, n, i - 1, j);// up |
        dfs(grid, m, n, i + 1, j);// down
        dfs(grid, m, n, i, j - 1);// <- west
        dfs(grid, m, n, i, j + 1); // east ->

    }
}