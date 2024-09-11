// class Solution {
// public:
//     int minimumTotal(vector<vector<int>>& triangle) {
//         int n = triangle.size();
        
//         // Iterate from the second last row to the first row
//         for (int row = n - 2; row >= 0; row--) {
//             for (int col = 0; col <= row; col++) {
//                 // Find the minimum path sum for the current element
//                 int bestBelow = min(triangle[row + 1][col], triangle[row + 1][col + 1]);
//                 triangle[row][col] += bestBelow;
//             }
//         }
        
//         // The top element now contains the minimum path sum
//         return triangle[0][0];
//     }
// };
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();

        // Iterate through each row starting from the second row
        for (int r = 1; r < n; r++) {
            for (int c = 0; c <= r; c++) {

                // Case 1: col == 0 (only one element directly above at (r - 1, 0))
                if (c == 0) {
                    int above = triangle[r - 1][c];
                    triangle[r][c] += above;

                // Case 2: col == row (only one element directly above at (r - 1, r - 1))
                } else if (c == r) {
                    int aboveLeft = triangle[r - 1][c - 1];
                    triangle[r][c] += aboveLeft;

                // Case 3: all other cases (two possible cells above: (r - 1, c - 1) and (r - 1, c))
                } else {
                    int aboveLeft = triangle[r - 1][c - 1];
                    int above = triangle[r - 1][c];
                    triangle[r][c] += min(aboveLeft, above);
                }
            }
        }

        // Find the minimum value in the last row
        int minVal = triangle[n - 1][0];
        for (int i = 1; i < triangle[n - 1].size(); i++) {
            minVal = min(minVal, triangle[n - 1][i]);
        }

        return minVal;
    }
};
