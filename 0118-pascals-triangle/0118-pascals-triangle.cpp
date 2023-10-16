class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        // talking 2 D vector
        vector<vector<int>> ans(numRows); 

        for(int i = 0; i < numRows; i++){
            //Resize the no of colmn according to no of row
            ans[i].resize(i+1);
            // defining its first and last element as 1
            ans[i][0] = ans[i][i] = 1;

            // filling column sum 
            for(int j = 1; j < i; j++){
                ans[i][j] = ans[i-1][j-1] + ans[i-1][j];
            }
        }
        return ans;
    }
};