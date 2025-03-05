class Solution {
public:
    // DFS function to calculate the area of the island
    int dfs(vector<vector<int>>& grid, int i, int j) {
        int n = grid.size();
        int m = grid[0].size();

        // Base case: If the current cell is out of bounds or is not 1, return 0
        if (i < 0 || i >= n || j < 0 || j >= m || grid[i][j] != 1) {
            return 0;
        }

        // Mark the current cell as visited (0)
        grid[i][j] = 0;

        // Initialize the area of the current island as 1 (current cell)
        int area = 1;

        // Recursively visit all four neighboring cells (up, down, left, right)
        area += dfs(grid, i - 1, j); // up
        area += dfs(grid, i + 1, j); // down
        area += dfs(grid, i, j - 1); // left
        area += dfs(grid, i, j + 1); // right

        return area;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int maxArea = 0; // Initialize the maximum area

        // Traverse the entire grid
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    // Perform DFS to calculate the area of the current island
                    int currentArea = dfs(grid, i, j);
                    // Update the maximum area
                    maxArea = max(maxArea, currentArea);
                }
            }
        }

        return maxArea;
    }
};



/*
class Solution {
public:
    //use basic dfs operation on the  grid
    int dfs(vector<vector<int>>&grid,int i,int j,int n,int m)
    {
	//checking corner cases for moving in 4 direction up down left right
        if(i>=0 and i<n and j>=0 and j<m and grid[i][j]==1)
        {
            grid[i][j]=0;//updating grid value
            //counting all the island  
            return 1+ dfs(grid,i+1,j,n,m)+dfs(grid,i-1,j,n,m)+dfs(grid,i,j+1,n,m)+dfs(grid,i,j-1,n,m);
            
        }
        return 0;
    }
    
    
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        int max_area=0;
        int n=grid.size();
        int m=grid[0].size();
        //moving every point of grid  and updating its value when you travelled
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                    int count=dfs(grid,i,j,n,m);
					//finding maximum area
                    max_area=max(max_area,count);
                }
            }
        }
        return max_area;
    }
};

*/