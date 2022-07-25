class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int ans = 1e6;
        int n = nums.size();
        int l = 0;
        int sum = 0;
        for(int i = 0; i < n; i++)
        {
            sum += nums[i];
            while(sum >= target)
            {
                ans = min(ans, i+1-l);
                sum -= nums[l];
                l++;
            }
        }
        
        
        return ans == 1e6 ? 0 : ans;
    }
};