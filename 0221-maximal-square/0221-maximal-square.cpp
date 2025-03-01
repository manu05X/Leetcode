class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();

        // DP table to store the size of the maximum square ending at each cell.
        vector<vector<int>> dp(row, vector<int>(col, 0));

        int maxEdge = 0; // Variable to keep track of the largest square's edge length.

        // Iterate through the matrix row-wise
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (matrix[i][j] == '1') { // Only process cells that contain '1'
                    
                    // If the cell is in the first row or first column, it can only form a 1x1 square.
                    if (i == 0 || j == 0) {
                        dp[i][j] = 1;
                    } else {
                        // The size of the square ending at (i, j) depends on the minimum square size 
                        // of the top (dp[i-1][j]), left (dp[i][j-1]), and top-left diagonal (dp[i-1][j-1]) cells.
                        dp[i][j] = min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1])) + 1;
                    }

                    // Update maxEdge if we find a larger square
                    maxEdge = max(maxEdge, dp[i][j]);
                }
            }
        }

        // Return the area of the largest square found.
        return maxEdge * maxEdge;
    }
};




/*
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        // Get the number of rows and columns in the matrix
        int row = matrix.size();
        int col = matrix[0].size();

        // Create a DP table of size (row+1) x (col+1) initialized with 0
        // The extra row and column help to avoid boundary checks
        vector<vector<int>> dp(row + 1, vector<int>(col + 1, 0));

        int maxEdge = 0; // Stores the length of the largest square found so far

        // Iterate through each cell in the given matrix
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                // If the current cell contains '1', it can contribute to a square
                if(matrix[i][j] == '1'){
                    // The size of the square ending at (i, j) is determined by 
                    // taking the minimum of the top, left, and top-left diagonal squares, then adding 1
                    dp[i + 1][j + 1] = min(dp[i][j], min(dp[i][j + 1], dp[i + 1][j])) + 1;
                    
                    // Update the maximum square size found so far
                    maxEdge = max(maxEdge, dp[i + 1][j + 1]);
                }
            }
        }

        // The area of the largest square is side_length²
        return maxEdge * maxEdge;
    }
};


// So when we map standard indices into the 1-based shifted DP array, we get:

// dp[i][j] → corresponds to dp[i+1][j+1]
// dp[i-1][j] (top) → corresponds to dp[i][j+1]
// dp[i][j-1] (left) → corresponds to dp[i+1][j]
// dp[i-1][j-1] (top-left diagonal) → corresponds to dp[i][j]

*/

