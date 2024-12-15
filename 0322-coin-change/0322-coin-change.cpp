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

Here is a step-by-step dry run for the input:


coins = [1, 2, 5]
amount = 11
Initialization:
We initialize the dp array with size amount + 1 (i.e., 12) and set all values to INT_MAX except dp[0] = 0, since 0 coins are needed to form amount 0.

Initial dp:
dp = [0, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF]
Outer Loop: Iterate over amounts i = 1 to amount = 11


For i = 1:
Iterate over coins:
Coin 1: dp[1] = min(dp[1], dp[1 - 1] + 1) = min(INF, 0 + 1) = 1
Coin 2: Skipped (2 > 1)
Coin 5: Skipped (5 > 1)
Updated dp:
dp = [0, 1, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF]


For i = 2:
Iterate over coins:
Coin 1: dp[2] = min(dp[2], dp[2 - 1] + 1) = min(INF, 1 + 1) = 2
Coin 2: dp[2] = min(dp[2], dp[2 - 2] + 1) = min(2, 0 + 1) = 1
Coin 5: Skipped (5 > 2)
Updated dp:
dp = [0, 1, 1, INF, INF, INF, INF, INF, INF, INF, INF, INF]


For i = 3:
Iterate over coins:
Coin 1: dp[3] = min(dp[3], dp[3 - 1] + 1) = min(INF, 1 + 1) = 2
Coin 2: dp[3] = min(dp[3], dp[3 - 2] + 1) = min(2, 1 + 1) = 2
Coin 5: Skipped (5 > 3)
Updated dp:
dp = [0, 1, 1, 2, INF, INF, INF, INF, INF, INF, INF, INF]


For i = 4:
Iterate over coins:
Coin 1: dp[4] = min(dp[4], dp[4 - 1] + 1) = min(INF, 2 + 1) = 3
Coin 2: dp[4] = min(dp[4], dp[4 - 2] + 1) = min(3, 1 + 1) = 2
Coin 5: Skipped (5 > 4)
Updated dp:
dp = [0, 1, 1, 2, 2, INF, INF, INF, INF, INF, INF, INF]


For i = 5:
Iterate over coins:
Coin 1: dp[5] = min(dp[5], dp[5 - 1] + 1) = min(INF, 2 + 1) = 3
Coin 2: dp[5] = min(dp[5], dp[5 - 2] + 1) = min(3, 2 + 1) = 3
Coin 5: dp[5] = min(dp[5], dp[5 - 5] + 1) = min(3, 0 + 1) = 1
Updated dp:
dp = [0, 1, 1, 2, 2, 1, INF, INF, INF, INF, INF, INF]


For i = 6:
Iterate over coins:
Coin 1: dp[6] = min(dp[6], dp[6 - 1] + 1) = min(INF, 1 + 1) = 2
Coin 2: dp[6] = min(dp[6], dp[6 - 2] + 1) = min(2, 2 + 1) = 2
Coin 5: dp[6] = min(dp[6], dp[6 - 5] + 1) = min(2, 1 + 1) = 2
Updated dp:
dp = [0, 1, 1, 2, 2, 1, 2, INF, INF, INF, INF, INF]


For i = 7:
Iterate over coins:
Coin 1: dp[7] = min(dp[7], dp[7 - 1] + 1) = min(INF, 2 + 1) = 3
Coin 2: dp[7] = min(dp[7], dp[7 - 2] + 1) = min(3, 1 + 1) = 2
Coin 5: dp[7] = min(dp[7], dp[7 - 5] + 1) = min(2, 1 + 1) = 2
Updated dp:
dp = [0, 1, 1, 2, 2, 1, 2, 2, INF, INF, INF, INF]


For i = 8:
Iterate over coins:
Coin 1: dp[8] = min(dp[8], dp[8 - 1] + 1) = min(INF, 2 + 1) = 3
Coin 2: dp[8] = min(dp[8], dp[8 - 2] + 1) = min(3, 2 + 1) = 3
Coin 5: dp[8] = min(dp[8], dp[8 - 5] + 1) = min(3, 2 + 1) = 3
Updated dp:
dp = [0, 1, 1, 2, 2, 1, 2, 2, 3, INF, INF, INF]


For i = 9:
Iterate over coins:
Coin 1: dp[9] = min(dp[9], dp[9 - 1] + 1) = min(INF, 3 + 1) = 4
Coin 2: dp[9] = min(dp[9], dp[9 - 2] + 1) = min(4, 2 + 1) = 3
Coin 5: dp[9] = min(dp[9], dp[9 - 5] + 1) = min(3, 2 + 1) = 3
Updated dp:
dp = [0, 1, 1, 2, 2, 1, 2, 2, 3, 3, INF, INF]


For i = 10:
Iterate over coins:
Coin 1: dp[10] = min(dp[10], dp[10 - 1] + 1) = min(INF, 3 + 1) = 4
Coin 2: dp[10] = min(dp[10], dp[10 - 2] + 1) = min(4, 3 + 1) = 4
Coin 5: dp[10] = min(dp[10], dp[10 - 5] + 1) = min(4, 1 + 1) = 2
Updated dp:
dp = [0, 1, 1, 2, 2, 1, 2, 2, 3, 3, 2, INF]


For i = 11:
Iterate over coins:
Coin 1: dp[11] = min(dp[11], dp[11 - 1] + 1) = min(INF, 2 + 1) = 3
Coin 2: dp[11] = min(dp[11], dp[11 - 2] + 1) = min(3, 3 + 1) = 3
Coin 5: dp[11] = min(dp[11], dp[11 - 5] + 1) = min(3, 2 + 1) = 3
Updated dp:
dp = [0, 1, 1, 2, 2, 1, 2, 2, 3, 3, 2, 3]


Final Output:
dp[11] = 3
Thus, the minimum number of coins to make amount 11 is 3.

*/




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