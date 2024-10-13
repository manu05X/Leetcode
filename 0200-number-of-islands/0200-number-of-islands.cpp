class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        ios_base::sync_with_stdio(false);  
        cin.tie(NULL);
        
        int n = grid.size();
        int m = grid[0].size();

        if(n == 0 || m == 0)
        {
            return 0;
        }
        int count = 0;

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(grid[i][j] == '1')
                {
                    dfs(grid,m,n,i,j);
                    count++;
                }
            }
        }
        return count;
    }
    void dfs(vector<vector<char>>& grid, int m, int n, int i, int j)
    {
        if(i < 0 || j < 0 || i >= n || j >= m || grid[i][j] != '1')
        {
            return;
        }

        grid[i][j] = 'X';
        dfs(grid,m,n,i-1,j); //up
        dfs(grid,m,n,i+1,j); // down
        dfs(grid,m,n,i,j-1); // <- west
        dfs(grid,m,n,i,j+1); // east->
    }
};