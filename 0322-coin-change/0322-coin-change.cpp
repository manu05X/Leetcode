class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // DP array to store the minimum coins needed for each amount
        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0; // Base case: 0 coins needed for amount 0

        // Fill the dp array
        for (int i = 1; i <= amount; i++) {
            for (int coin : coins) {
                if (coin <= i && dp[i - coin] != INT_MAX) {
                    dp[i] = min(dp[i], dp[i - coin] + 1);
                }
            }
        }

        // If dp[amount] is still INT_MAX, it means the amount cannot be formed
        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
};




/*
class Solution {
public:
    int getCount(vector<int>& coins, int n, int amount) {
        // If amount becomes 0, we've successfully made up the amount
        if (amount == 0) {
            return 0;
        }

        // If no coins are left or the amount is negative, no solution exists
        if (n == 0 || amount < 0) {
            return INT_MAX; // Return a large value to signify no solution
        }

        // Exclude the last coin
        int exclude = getCount(coins, n - 1, amount);

        // Include the last coin
        int include = getCount(coins, n, amount - coins[n - 1]);
        if (include != INT_MAX) {
            include += 1; // Add 1 for using this coin
        }

        // Return the minimum of the two choices
        return min(exclude, include);
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        int ans = getCount(coins, n, amount);

        // If no valid solution, return -1
        return ans == INT_MAX ? -1 : ans;
    }
};

*/