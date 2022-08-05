class Solution {
public:
    int combinationSum4(vector<int>& nums, int t) {
        vector<unsigned long long> count(t+1, 0);
        count[0] = 1;
        
        for(int i=1; i < count.size(); i++)
        {
            for(int j = 0; j < nums.size(); j++)
            {
                if(i-nums[j] >= 0)
                {
                    count[i] += count[i - nums[j]];
                }
            }
        }
        return count[t];
    }
};