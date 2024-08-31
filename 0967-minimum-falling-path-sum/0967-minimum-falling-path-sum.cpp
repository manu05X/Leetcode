class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size(); // Number of rows
        int m = matrix[0].size(); // Number of columns

        vector<int> prev(m, 0); // Previous row's minimum path sums
        vector<int> cur(m, 0);  // Current row's minimum path sums

        // Initialize the first row (base condition)
        for (int j = 0; j < m; j++) {
            prev[j] = matrix[0][j];
        }

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < m; j++) {
                // Calculate the minimum path sum for the current cell considering three possible directions: up, left diagonal, and right diagonal

                // Up direction
                int up = matrix[i][j] + prev[j];

                // Left diagonal direction (if it's a valid move)
                int leftDiagonal = matrix[i][j];
                if (j - 1 >= 0) {
                    leftDiagonal += prev[j - 1];
                } else {
                    leftDiagonal += 1e9; // A very large positive value to represent an invalid path
                }

                // Right diagonal direction (if it's a valid move)
                int rightDiagonal = matrix[i][j];
                if (j + 1 < m) {
                    rightDiagonal += prev[j + 1];
                } else {
                    rightDiagonal += 1e9; // A very large positive value to represent an invalid path
                }

                // Store the minimum of the three paths in the current row
                cur[j] = min(up, min(leftDiagonal, rightDiagonal));
            }

            // Update the 'prev' array with the values from the 'cur' array for the next iteration
            prev = cur;
        }

        // Find the minimum value in the last row of 'prev', which represents the minimum path sums ending at each cell
        int minSum = INT_MAX;
        for (int j = 0; j < m; j++) {
            minSum = min(minSum, prev[j]);
        }

        // The minimum falling path sum is the minimum value in the last row of 'prev'
        return minSum;
    }
};