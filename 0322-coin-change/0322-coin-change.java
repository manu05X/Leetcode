/*
class Solution {
    // Recursive function to find the minimum number of coins to make up the amount
    int getCount(int[] coins, int n, int amount) {
        // Base case: If amount is 0, no coins are needed
        if (amount == 0) {
            return 0;
        }
        // Base case: If amount is negative or no coins left, not possible to make up the amount
        if (amount < 0 || n == 0) {
            return Integer.MAX_VALUE; // Use a large value to indicate an impossible case
        }

        // Recursive case 1: Include the current coin
        int include = getCount(coins, n, amount - coins[n - 1]);
        if (include != Integer.MAX_VALUE) {
            include += 1; // Add one coin used
        }

        // Recursive case 2: Exclude the current coin
        int exclude = getCount(coins, n - 1, amount);

        // Return the minimum of including or excluding the current coin
        return Math.min(include, exclude);
    }

    public int coinChange(int[] coins, int amount) {
        int n = coins.length; // Number of coins
        int result = getCount(coins, n, amount);
        return result == Integer.MAX_VALUE ? -1 : result; // Return -1 if no solution is found
    }
}
*/

class Solution {
    public int coinChange(int[] coins, int amount) {
        // Initialize DP array with a value greater than any possible number of coins
        int[] dp = new int[amount + 1];
        Arrays.fill(dp, amount + 1); // Set initial value to amount + 1 (impossible value)
        dp[0] = 0; // Base case: 0 coins needed to make amount 0

        // Update DP array
        for (int i = 1; i <= amount; i++) {
            for (int j = 0; j < coins.length; j++) {
                if (coins[j] <= i) {
                    dp[i] = Math.min(dp[i], dp[i - coins[j]] + 1);
                }
            }
        }

        // Return result
        return dp[amount] > amount ? -1 : dp[amount];
    }
}

