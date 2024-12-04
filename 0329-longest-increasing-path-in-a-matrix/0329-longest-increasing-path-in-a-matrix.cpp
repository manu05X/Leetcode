class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>> dp(n, vector<int>(m,-1));
        int maxLength = 0;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                maxLength = max(maxLength, dfs(matrix, dp, i,j,n,m, INT_MIN));
            }
        }

        return maxLength;
    }

    int dfs(vector<vector<int>>& matrix, vector<vector<int>>& dp, int i, int j, int n, int m, int preValue){
        if(i < 0 || i >= n || j < 0 || j >= m || matrix[i][j] <= preValue){
            return 0;
        }

        // Return precomputed value if the result for this cell is already calculated
        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        int currCellValue = matrix[i][j];

        matrix[i][j] = -1; // mark it as visited;

        int maxPath = 0; // Stores the maximum path length from the current cell

        // Go in each direction, and check which path yields the maximum length path
        // This is giving TLE, so we will have to memoize the code

        int down = dfs(matrix, dp, i+1, j, n, m, currCellValue) ;
        int up = dfs(matrix, dp, i-1, j, n, m, currCellValue) ;
        int right = dfs(matrix, dp, i, j+1, n, m, currCellValue) ;
        int left = dfs(matrix, dp, i, j-1, n, m, currCellValue) ;


        maxPath = 1 + max(max(down, up), max(left,right));

        matrix[i][j] = currCellValue;

        dp[i][j] = maxPath;

        return maxPath;

    }

};