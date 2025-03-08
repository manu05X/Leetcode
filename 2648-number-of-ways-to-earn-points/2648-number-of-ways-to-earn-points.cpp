class Solution {
public:
    int waysToReachTarget(int target, vector<vector<int>>& types) {
        int MOD = 1e9 + 7;
        int n = types.size();
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));
        
        // Base case: There's one way to achieve 0 points, which is by not selecting any questions.
        dp[0][0] = 1;
        
        for (int i = 1; i <= n; ++i) {
            int count = types[i-1][0];
            int marks = types[i-1][1];
            
            for (int j = 0; j <= target; ++j) {
                dp[i][j] = dp[i-1][j]; // Not using the i-th type
                
                for (int k = 1; k <= count; ++k) {
                    if (j - k * marks >= 0) {
                        dp[i][j] = (dp[i][j] + dp[i-1][j - k * marks]) % MOD;
                    } else {
                        break;
                    }
                }
            }
        }
        
        return dp[n][target];
    }
};


/*
class Solution {
public:
    int helper(int target, vector<vector<int>>& types, int index) {
        // Base case: If target is 0, we have found a valid way
        if (target == 0) {
            return 1;
        }
        // Base case: If we have exhausted all types or target is negative, no valid way
        if (index >= types.size() || target < 0) {
            return 0;
        }

        int count = types[index][0];
        int marks = types[index][1];
        int ways = 0;

        // Try including 0 to count questions of the current type
        for (int k = 0; k <= count; ++k) {
            if (target - k * marks >= 0) {
                ways += helper(target - k * marks, types, index + 1);
            } else {
                break;
            }
        }

        return ways;
    }


    int waysToReachTarget(int target, vector<vector<int>>& types) {
       return helper(target, types, 0);
    }
};

*/