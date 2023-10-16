class Solution {
public:
    vector<int> getRow(int numRows) {
         // talking 2 D vector
        vector<vector<int>> ans;
         //{1} and {1, 1}, are manually added to the result vector using result.push_back().
        ans.push_back({1});
        //The loop starts from i = 2 and continues until i reaches rowIndex.
        for(int i = 1; i < numRows+1; i++){
           vector<int> temp(i + 1, 1);

            // filling curr row sum by adding previous row elements 
            for(int j = 1; j < i; j++){
                temp[j] = ans[i-1][j] + ans[i-1][j-1];
            }
            //added to the result vector
            ans.push_back(temp);
        }
        return ans[numRows];
    }
};