class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<int> > dp(m + 1, vector<int> (n + 1, 0));
        dp[0][1] = 1;
        for (int i = 1; i <= m; i++)
            for (int j = 1; j <= n; j++)
                if (!obstacleGrid[i - 1][j - 1])
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        return dp[m][n];
    } 
};

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