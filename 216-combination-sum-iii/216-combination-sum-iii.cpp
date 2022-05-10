class Solution {
public:
    void SumUntil(vector<vector<int>>& ans, vector<int>& combination, int k, int target, int start){
        if(combination.size() == k && target == 0)
        {
            ans.push_back(combination);
            return;
        }
        // if(combination.size() < k)
    
          for(int i = start; i <= 9; i++)
          {
                if(target - i < 0)
                    break;
                combination.push_back(i);
                SumUntil(ans, combination, k, target-i,i+1);
                combination.pop_back();
            }  
        
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> combination;

        SumUntil(ans,combination,k,n,1);
        return ans;
    }
};