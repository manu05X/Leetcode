class Solution {
    int dfs(int[][] grid, int n, int m, int i, int j){
        if (i < 0 || i >= n || j < 0 || j >= m || grid[i][j] == 0) {
            return 0;
        }

        int currFish = grid[i][j];
        grid[i][j] = 0;

        // Explore all 4 directions and accumulate the fish count
        currFish += dfs(grid, n, m, i - 1, j); // Up
        currFish += dfs(grid, n, m, i + 1, j); // Down
        currFish += dfs(grid, n, m, i, j - 1); // Left
        currFish += dfs(grid, n, m, i, j + 1); // Right

        return currFish;

    }

    public int findMaxFish(int[][] grid) {
        int n = grid.length;
        int m = grid[0].length;

        int ans = 0;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] != 0){
                    ans = Math.max(ans, dfs(grid, n, m, i,j));
                }
            }
        }

        return ans;
    }
}