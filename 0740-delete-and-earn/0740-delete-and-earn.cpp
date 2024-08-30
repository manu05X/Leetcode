class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        
        vector<int> a(1e4+1, 0);
        int maxi = *max_element(nums.begin(), nums.end());
        for(auto i: nums) a[i]+=i;

        vector<int> dp(1e4+1, 0);
        dp[1] = a[1];

        for(int i=2; i<maxi+1; i++)
        {
            dp[i] = max(dp[i-1], a[i] + dp[i-2]);
        }

        return dp[maxi];
    }
};