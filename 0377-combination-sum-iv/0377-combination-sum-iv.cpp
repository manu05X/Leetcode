class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<unsigned int> dp(target+1, 0);

        dp[0] = 1;

        for(int currSum = 1; currSum < target+1; currSum++){
            for(int num : nums){
                if(currSum - num >= 0){
                    dp[currSum] += dp[currSum-num];
                } 
            }
        }

        return dp[target];
    }
};