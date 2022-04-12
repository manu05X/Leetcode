class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int totalSum = 0;
        for(int i = 0; i < nums.size(); i++)
            totalSum +=nums[i];
        
        if(totalSum%2 != 0)
            return false;
        
        int sum = totalSum/2;
        
        bool dp[sum+1][n+1];
        for(int i = 0; i < n; i++)
            dp[0][i] = true;
        
        for(int i = 0; i < sum+1; i++)
            dp[i][0] = false;
        
        for(int i = 1; i < sum+1; i++)
        {
            for(int j = 1; j < n+1; j++)
            {
                dp[i][j] = dp[i][j-1];
                if(i >= nums[j-1])
                {
                    dp[i][j] = dp[i][j] || dp[i-nums[j-1]][j-1];
                }
            }
        }
        return dp[sum][n];
    }
};