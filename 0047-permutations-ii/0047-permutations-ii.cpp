class Solution {
public:
   void dfs(vector<int>& nums, int idx, vector<vector<int>>& ans) {
        if (idx == nums.size()) {
            ans.push_back(nums);
            return;
        }
        
        for (int i = idx; i < nums.size(); i++) {
            if (i == idx || nums[i] != nums[idx]) {
                swap(nums[idx], nums[i]);
                dfs(nums, idx + 1, ans);
            }
        }
        sort(nums.begin() + idx, nums.end());
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        dfs(nums, 0, ans);
        return ans;
    }
};

