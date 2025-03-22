class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> result;
    if (matrix.empty()) return result;

    int m = matrix.size();    // Number of rows
    int n = matrix[0].size(); // Number of columns

    // Direction arrays for row and column movements
    int dir_row[] = {0, 1, 0, -1}; // Right, Down, Left, Up
    int dir_col[] = {1, 0, -1, 0}; // Right, Down, Left, Up

    // Boundaries
    int top = 0, bottom = m - 1;
    int left = 0, right = n - 1;

    int row = 0, col = 0; // Starting position
    int dir = 0;          // Start with right direction

    for (int i = 0; i < m * n; ++i) {
        result.push_back(matrix[row][col]);

        // Calculate next position
        int next_row = row + dir_row[dir];
        int next_col = col + dir_col[dir];

        // Check if next position is within boundaries
        if (next_row >= top && next_row <= bottom && next_col >= left && next_col <= right) {
            row = next_row;
            col = next_col;
        } else {
            // Change direction and update boundaries
            dir = (dir + 1) % 4; // Cycle through directions
            row += dir_row[dir];
            col += dir_col[dir];

            // Update boundaries after changing direction
            if (dir == 1) top++;      // After moving right, increment top
            else if (dir == 2) right--; // After moving down, decrement right
            else if (dir == 3) bottom--; // After moving left, decrement bottom
            else if (dir == 0) left++;   // After moving up, increment left
        }
    }

    return result;
    }
};


/*
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        vector<int> ans;

        // Initialize the pointers reqd for traversal.
        int top = 0, left = 0, bottom = row - 1, right = col - 1;

        while(top <= bottom && left <= right){
            //left to right
            for(int i = left; i <= right; i++){
                ans.push_back(matrix[top][i]);
            }
            top++;
            // top to bottom
            for(int i = top; i <= bottom; i++){
                ans.push_back(matrix[i][right]);
            }
            right--;

            /*
            //right to left
            for(int i = right; i >=left; i--){
                ans.push_back(matrix[bottom][i]);
            }
            bottom--;
            */
            
            /*
            // For moving right to left.
            if (top <= bottom) 
            {
                for (int i = right; i >= left; i--)
                    ans.push_back(matrix[bottom][i]);

                bottom--;
            }

            // For moving bottom to top.
            if (left <= right) 
            {
                for (int i = bottom; i >= top; i--)
                    ans.push_back(matrix[i][left]);

                left++;
            }

        }
        return ans;
    }
};
*/