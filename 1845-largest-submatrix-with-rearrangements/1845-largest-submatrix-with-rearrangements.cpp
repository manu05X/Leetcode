class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();   // Number of rows
        int n = matrix[0].size(); // Number of columns
        int ans = 0;  // Variable to store the maximum area

        // Step 1: Convert matrix to column heights
        for (int row = 0; row < m; row++) {
            for (int col = 0; col < n; col++) {
                // If the current cell is 1 and it's not in the first row
                if (matrix[row][col] != 0 && row > 0) {
                    matrix[row][col] += matrix[row - 1][col];  // Add previous row's value
                }
            }
            
            // Step 2: Sort the row in descending order to maximize area
            vector<int> currRow = matrix[row];
            sort(currRow.begin(), currRow.end(), greater<int>()); // Sort in descending order

            // Step 3: Calculate the largest possible submatrix area
            for (int i = 0; i < n; i++) {
                int area = currRow[i] * (i + 1);  // Height * Width
                ans = max(ans, area);  // Update maximum area
            }
        }
        
        return ans; // Return the maximum found area
    }
};


/*
[[0,0,1],
 [1,1,1],
 [1,0,1]]


{{0, 0, 1}, 
 {1, 1, 2}, 
 {2, 0, 3}}

*/