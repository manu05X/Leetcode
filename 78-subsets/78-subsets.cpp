class Solution {
public:
    void dfs(vector<vector<int>>& ans,vector<int>& subset,vector<int>& nums, int left)
    {
        ans.push_back(subset);
        
        for(int i = left; i < nums.size(); i++)
        {
            subset.push_back(nums[i]); // including nums[i]
            dfs(ans,subset,nums,i+1);  // move to next element
            subset.pop_back();  // exclude nums[i] from subset and trigger backtracking
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> subset;
        
        dfs(ans,subset,nums,0);
        
        return ans;
    }
};