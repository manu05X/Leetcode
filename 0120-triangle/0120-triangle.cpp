class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        
        // Iterate from the second last row to the first row
        for (int row = n - 2; row >= 0; row--) {
            for (int col = 0; col <= row; col++) {
                // Find the minimum path sum for the current element
                int bestBelow = min(triangle[row + 1][col], triangle[row + 1][col + 1]);
                triangle[row][col] += bestBelow;
            }
        }
        
        // The top element now contains the minimum path sum
        return triangle[0][0];
    }
};
