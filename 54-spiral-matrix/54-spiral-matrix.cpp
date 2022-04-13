class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int rows=matrix.size();
        if(rows == 0)
            return {};
		 vector<int> ans;
        int cols = matrix[0].size();
        if(rows == 1){
            for(int i=0; i < cols; i++){
                ans.push_back(matrix[0][i]);                
            }
            return ans;
        }
        if(cols == 1)
        {
            for(int i = 0; i < rows; i++)
            {
                ans.push_back(matrix[i][0]);                
            }
            return ans;
        }
        
        
        
        // int rows = matrix.size();
        // int cols = matrix[0].size();
        int top = 0, left = 0, bottom = rows-1, right = cols-1;
        
        //vector<int> ans;
        while(top <= bottom && left <= right)
        {
            for(int i = left; i <= right; i++)
                ans.push_back(matrix[top][i]);
            top++;
            
            for(int i = top; i <= bottom; i++)
                ans.push_back(matrix[i][right]);
            right--;
            
            if(top <= bottom)
            {
                for(int i = right; i >= left; i--)
                    ans.push_back(matrix[bottom][i]);
                bottom--;
            }
            
            if(left <= right)
            {
                for(int i = bottom; i >= top; i--)
                    ans.push_back(matrix[i][left]);
                left++;
            }
        }
        return ans;
        
    }
};