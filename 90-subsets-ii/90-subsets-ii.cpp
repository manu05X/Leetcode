class Solution {
public:
    void subsetUntil(vector<int>& nums,vector<int>& subset,vector<vector<int>>& ans, int left)
{   
        // for(int i = 0; i < ans.size(); i++)
        // {
        //     for(int j = 0; j < subset.size(); j++)
        //     {
        //         if(ans[i][j] == )
        //     }
        // }
            ans.push_back(subset);
        
    for(int i = left; i < nums.size(); i++)
    {
        if(i == left || nums[i] != nums[i-1])
        {
            subset.push_back(nums[i]); // including nums[i]
            subsetUntil(nums,subset,ans,i+1); // move to next element
            subset.pop_back(); // exclude nums[i] from subset and trigger backtracking
        }
    }
    //return;
}
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        
        vector<int> subset;
        sort(nums.begin(), nums.end());
        subsetUntil(nums,subset,ans, 0);

        return ans;
    }
};