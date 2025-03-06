class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        // If the starting cell is blocked, no paths exist
        if (obstacleGrid[0][0] == 1) return 0;

        // Create a 1D array to store the number of paths for the current row
        vector<int> dp(n, 0);

        // Initialize the first cell
        dp[0] = 1;

        // Fill the first row
        for (int j = 1; j < n; j++) {
            if (obstacleGrid[0][j] == 1) {
                dp[j] = 0; // If the cell is blocked, no paths exist
            } else {
                dp[j] = dp[j - 1]; // Carry over the paths from the left
            }
        }

        // Fill the rest of the grid
        for (int i = 1; i < m; i++) {
            // Handle the first column
            if (obstacleGrid[i][0] == 1) {
                dp[0] = 0; // If the cell is blocked, no paths exist
            }

            for (int j = 1; j < n; j++) {
                if (obstacleGrid[i][j] == 1) {
                    dp[j] = 0; // If the cell is blocked, no paths exist
                } else {
                    dp[j] += dp[j - 1]; // Add paths from above and left
                }
            }
        }

        // Return the number of unique paths to the bottom-right corner
        return dp[n - 1];
    }
};

/*
class Solution {
public:
    int uniquePathsWithObstacles(vector<std::vector<int>>& obstacleGrid) {
        if (obstacleGrid.empty() || obstacleGrid[0].empty() || obstacleGrid[0][0] == 1) {
            return 0;
        }
        
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        
        vector<int> previous(n, 0);
        vector<int> current(n, 0);
        previous[0] = 1;
        
        for (int i = 0; i < m; i++) {
            current[0] = obstacleGrid[i][0] == 1 ? 0 : previous[0];
            for (int j = 1; j < n; j++) {
                current[j] = obstacleGrid[i][j] == 1 ? 0 : current[j-1] + previous[j];
            }
            previous = current;
        }
        
        return previous[n-1];
    }
};

*/

/*
Example
Using the earlier example:

0 0 0
0 1 0
0 0 0
​

Here's how the previous and current arrays evolve:

The function's output matches the example description:

Initial State:

previous: [1,0,0]
current: [0,0,0] => j=0 -> [1,0,0] => j=1 -> [1,1,0] => j=2 -> [1,1,1]
After processing row 0:

previous: [1,0,0]
current: [1,1,1]
After processing row 1:

previous: [1,1,1]
current: [1,0,1]
After processing row 2:

previous: [1,0,1]
current: [1,1,2]
From the final state of the previous array, we can infer that there are 2 unique paths from the top-left to the bottom-right corner, avoiding obstacles. This matches the expected result.



*/