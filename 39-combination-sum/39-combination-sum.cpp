class Solution {
public:
    void SumUntial(vector<int>& candidates,vector<vector<int>>& ans,vector<int>& combination,int target,int left)
    {
        if(target==0)
        {
            ans.push_back(combination);
            return;
        }
        for(int i = left; i < candidates.size(); i++)
        {
            if(target >= candidates[i])
            {
                combination.push_back(candidates[i]);
                SumUntial(candidates,ans,combination,target-candidates[i],i);
                combination.pop_back();
            }
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        
        vector<vector<int>> ans;
        vector<int> combination;
        
        SumUntial(candidates,ans,combination,target,0);
        return ans;        
    }
};