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