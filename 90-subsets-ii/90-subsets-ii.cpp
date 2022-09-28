class Solution {
public:
    void dfs(vector<vector<int>>& ans, vector<int>& subset,vector<int>& nums, int left){
        ans.push_back(subset);
        
        for(int i = left; i < nums.size(); i++)
        {
            if(i == left || nums[i] != nums[i-1])
            {
                subset.push_back(nums[i]);
                dfs(ans,subset,nums,i+1);
                subset.pop_back();
            }  
        }    
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> subset;
        sort(nums.begin(),nums.end());
        dfs(ans,subset,nums,0);
        
        return ans;
    }
};