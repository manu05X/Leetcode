class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        // here we need to initialize thr dp array for 365 days but it wold be too big so w can initialize only for last day of days array
        int lastDay = days[days.size() - 1];
        
        // Initialize a DP array to store the minimum cost for each day up to `lastDay`.
        // `dp[day]` will represent the minimum cost to travel up to and including `day`.
        vector<int> dp(lastDay + 1, 0);
        
        // `i` is used to iterate through the `days` array.
        int i = 0;
        
        // Iterate through each day from 1 to `lastDay`.
        for (int day = 1; day <= lastDay; day++) {
            // If the current day is not in the `days` array, the cost remains the same as the previous day.
            if (day < days[i]) {
                dp[day] = dp[day - 1];
            } else {
                // If the current day is in the `days` array, calculate the minimum cost:
                // 1. Buy a 1-day pass: cost = dp[day - 1] + costs[0]
                // 2. Buy a 7-day pass: cost = dp[max(0, day - 7)] + costs[1]
                // 3. Buy a 30-day pass: cost = dp[max(0, day - 30)] + costs[2]
                i++;
                dp[day] = min({dp[day - 1] + costs[0],
                               dp[max(0, day - 7)] + costs[1],
                               dp[max(0, day - 30)] + costs[2]});
            }
        }
     
        // Return the minimum cost to travel up to the last day.
        return dp[lastDay];
    }
};