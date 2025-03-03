class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long long> dp(n + 1, 0); // Extra space for out-of-bound access
        
        // Traverse from the last question to the first
        for (int i = n - 1; i >= 0; --i) {
            int points = questions[i][0];
            int skip = questions[i][1];

            // Option 1: Solve this question
            long long solve = points;
            if (i + skip + 1 < n) solve += dp[i + skip + 1];

            // Option 2: Skip this question
            long long skipQuestion = dp[i + 1];

            // Take the maximum of both choices
            dp[i] = max(solve, skipQuestion);
        }

        return dp[0]; // Max points starting from question 0
    }
};
