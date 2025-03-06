class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();

        // Base cases
        if (n == 0) return 0;
        if (n == 1) return cost[0];

        // Initialize variables for (i-1) and (i-2)
        int prev1 = cost[1]; // minimum cost to reach step 1
        int prev2 = cost[0]; // minimum cost to reach step 0

        // Iterate from step 2 to (n-1)
        for (int i = 2; i < n; i++) {
            int current = cost[i] + min(prev1, prev2); // minimum cost to reach step i
            prev2 = prev1; // update prev2 to prev1
            prev1 = current; // update prev1 to current
        }

        // The top is beyond the last step, so return the minimum of the last two steps
        return min(prev1, prev2);
    }
};