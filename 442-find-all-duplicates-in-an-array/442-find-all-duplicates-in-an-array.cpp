class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        for(int i = 0; i < n; i++)
        {
            int idx = abs(nums[i]);
            if(nums[idx-1] < 0)
            {
                ans.push_back(abs(nums[i]));
            }
            nums[idx-1] = -nums[idx-1];
        }
        return ans;
    }
};