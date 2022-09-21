class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) 
    {
        int sum = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i]%2 == 0)
                sum+=nums[i];
        }
        
        vector<int> ans(queries.size());
        
        for(int i = 0; i < queries.size(); i++)
        {
            int val = queries[i][0], idx = queries[i][1];
            
            if(nums[idx]%2 == 0)
                sum -= nums[idx];
            nums[idx] += val;
            if(nums[idx] % 2 == 0)
                sum += nums[idx];
            ans[i] = sum;
        }
        return ans;
    }
};