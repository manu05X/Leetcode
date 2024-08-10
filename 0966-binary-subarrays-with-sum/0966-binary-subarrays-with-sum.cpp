class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();

        unordered_map<int,int> preSum_freq_map;
        int totalCount = 0;
        int currSum = 0;

        for(int i = 0; i < n; i++)
        {
            currSum += nums[i];
            if(currSum == goal)
            {
                totalCount++;
            }

            if(preSum_freq_map.find(currSum-goal) != preSum_freq_map.end())
            {
                totalCount += preSum_freq_map[currSum-goal];
            }

            preSum_freq_map[currSum]++;
        }
        return totalCount;
    }
};