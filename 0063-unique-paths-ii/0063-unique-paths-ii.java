class Solution {
    public int uniquePathsWithObstaclesRecur(int i, int j, int rows, int cols, int[][]obstacleGrid, int[][] pathArray){
        // check the boundary constraints
        if(i == rows || j == cols){
            return 0;
        }
        // check if obastacle is present or not
        if(obstacleGrid[i][j] == 1){
            return 0;
        }

        // check the base case when the last cell is reached
        if(i == rows-1 && j == cols-1){
            return 1;
        }

        if(pathArray[i][j] != -1){
            return pathArray[i][j];
        }

        // using the recursive appraoch when moving to next row or next column 
        pathArray[i][j] = uniquePathsWithObstaclesRecur(i+1, j, rows, cols, obstacleGrid, pathArray) + uniquePathsWithObstaclesRecur(i, j+1, rows, cols, obstacleGrid, pathArray);

        return pathArray[i][j];

    }
    public int uniquePathsWithObstacles(int[][] obstacleGrid) {
        int rows = obstacleGrid.length;   // Number of rows
        int cols = obstacleGrid[0].length; // Number of columns

        int[][] pathArray = new int[rows][cols];
		for (int[] row: pathArray){
			Arrays.fill(row, -1);
		}

        return uniquePathsWithObstaclesRecur(0, 0, rows, cols, obstacleGrid, pathArray);
    }
}


/*
class Solution {
    public int uniquePathsWithObstaclesRecur(int i, int j, int rows, int cols, int[][]obstacleGrid){
        // check the boundary constraints
        if(i == rows || j == cols){
            return 0;
        }
        // check if obastacle is present or not
        if(obstacleGrid[i][j] == 1){
            return 0;
        }

        // check the base case when the last cell is reached
        if(i == rows-1 && j == cols-1){
            return 1;
        }
        // using the recursive appraoch when moving to next row or next column 
        return uniquePathsWithObstaclesRecur(i+1, j, rows, cols, obstacleGrid) + uniquePathsWithObstaclesRecur(i, j+1, rows, cols, obstacleGrid);

    }
    public int uniquePathsWithObstacles(int[][] obstacleGrid) {
        int rows = obstacleGrid.length;   // Number of rows
        int cols = obstacleGrid[0].length; // Number of columns

        return uniquePathsWithObstaclesRecur(0, 0, rows, cols, obstacleGrid);
    }
}

*/



/*
class Solution {
    public int uniquePathsWithObstacles(int[][] obstacleGrid) {
        int n = obstacleGrid.length;   // Number of rows
        int m = obstacleGrid[0].length; // Number of columns

        // If the starting cell (0,0) has an obstacle, there is no path to the destination
        if (obstacleGrid[0][0] == 1) {
            return 0;
        }

        // Initialize the starting cell, Number of ways of reaching the starting cell = 1.
        obstacleGrid[0][0] = 1;

        // Fill the first column, considering obstacles
        for (int i = 1; i < n; i++) {
            if (obstacleGrid[i][0] == 0 && obstacleGrid[i - 1][0] == 1) {
                obstacleGrid[i][0] = 1;  // If there is no obstacle, inherit path from the top
            } else {
                obstacleGrid[i][0] = 0;  // Otherwise, set paths to zero
            }
        }

        // Fill the first row, considering obstacles
        for (int i = 1; i < m; i++) {
            if (obstacleGrid[0][i] == 0 && obstacleGrid[0][i - 1] == 1) {
                obstacleGrid[0][i] = 1;  // If there is no obstacle, inherit path from the left
            } else {
                obstacleGrid[0][i] = 0;  // Otherwise, set paths to zero
            }
        }

        // Fill the rest of the grid using dynamic programming
        // Starting from obstacleGrid[1][1], we fill up the values.
		// The number of ways of reaching obstacleGrid[i][j] = obstacleGrid[i - 1][j] + obstacleGrid[i][j - 1]
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                if (obstacleGrid[i][j] == 1) {
                    obstacleGrid[i][j] = 0;  // If obstacle, set paths to zero
                } else {
                    // Sum of paths from the left cell and top cell
                    obstacleGrid[i][j] = obstacleGrid[i][j - 1] + obstacleGrid[i - 1][j];
                }
            }
        }

        // Return the value in the bottom-right cell, which represents the number of unique paths
        return obstacleGrid[n - 1][m - 1];
    }
}
*/