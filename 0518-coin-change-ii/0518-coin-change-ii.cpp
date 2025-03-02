class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<unsigned long long> dp(amount + 1, 0); // Use long long to prevent overflow
        dp[0] = 1;

        for (int coin : coins) {
            for (int i = coin; i <= amount; i++) {
                dp[i] += dp[i - coin];  // Accumulate ways using this coin
            }
        }
        
        return dp[amount] > INT_MAX ? 0 : dp[amount];  // Return result safely
    }
};
