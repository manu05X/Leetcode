class Solution {
public:
    void dfs(vector<vector<int>>& ans,vector<int>& temp,vector<int>& nums, int left)
    {
        ans.push_back(temp);// push the current subset into the resultant array
        for(int i = left; i < nums.size(); i++)
        {
            if(i == left || nums[i] != nums[i-1])
            {
                temp.push_back(nums[i]); // add the current element to consider the subsets corresponding to it
                dfs(ans,temp,nums,i+1);  //generate subsets for this array
                // as this has been used, pop it
                temp.pop_back();  // exclude nums[i] from subset and trigger backtracking
            } 
        }
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        sort(nums.begin(), nums.end());
        dfs(ans,temp,nums,0);
        
        return ans;
    }
};

/*
[1,2,2]
Normal subset
index : [[],[0],[0,1],[0,1,2],[0,2],[1],[1,2],[2]]
Ans:    [[],[1],[1,2],[1,2,2],[1,2],[2],[2,2],[2]]

without duplicate
index : [[],[0],[0,1],[0,1,2],[1],[1,2]]
ans:    [[],[1],[1,2],[1,2,2],[2],[2,2]]
*/