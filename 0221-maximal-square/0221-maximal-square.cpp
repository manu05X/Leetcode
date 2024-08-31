class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();

        vector<vector<int>> dp(row+1,vector<int>(col+1,0));

        int maxEdge = 0;
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(matrix[i][j] == '1'){
                     // The size of the square ending at (i, j) is the minimum of the three  neighboring squares plus 1.
                    dp[i + 1][j + 1] = min(dp[i][j], min(dp[i][j + 1], dp[i + 1][j])) + 1;
                    // Update the maximum size found so far.
                    maxEdge = max(maxEdge, dp[i + 1][j + 1]);
                }
            }
        }

        return maxEdge* maxEdge;
    }
};