class Solution {
public:
    void permuteUntil( vector<vector<int>>& res,vector<int>& nums, int idx)
    {
        if(idx == nums.size())
        {
            res.push_back(nums);
            return;
        }
        
        unordered_set<int> seen;
        for(int i = idx; i < nums.size(); i++)
        {
            if(seen.find(nums[i]) == seen.end())
            {
                swap(nums[idx], nums[i]);
                permuteUntil(res,nums, idx+1);
                swap(nums[idx], nums[i]);
                seen.insert(nums[i]);
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n = nums.size();
        
        vector<vector<int>> res;
        
        permuteUntil(res,nums, 0);
        
        return res;
    }
};