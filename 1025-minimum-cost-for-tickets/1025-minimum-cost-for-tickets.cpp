// class Solution {
// public:
//     int mincostTickets(vector<int>& days, vector<int>& costs) {
//         // here we need to initialize thr dp array for 365 days but it wold be too big so w can initialize only for last day of days array
//         int lastDay = days[days.size() - 1];
//         vector<int> dp(lastDay + 1, 0);
        
//         int i = 0;
//         for (int day = 1; day <= lastDay; day++) {
//             if (day < days[i]) {
//                 dp[day] = dp[day - 1];
//             } else {
//                 i++;
//                 dp[day] = min({dp[day - 1] + costs[0],
//                                dp[max(0, day - 7)] + costs[1],
//                                dp[max(0, day - 30)] + costs[2]});
//             }
//         }
     
//         return dp[lastDay];
//     }
// };



class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int> dp(n, 0);
        
        for (int i = n - 1; i >= 0; --i) {
            // 1-day pass cost
            int opt1 = costs[0] + (i + 1 < n ? dp[i + 1] : 0);
            
            // 7-day pass cost
            int after7 = days[i] + 6;
            auto it7 = upper_bound(days.begin() + i, days.end(), after7);
            int j7 = it7 - days.begin();
            int opt2 = costs[1] + (j7 < n ? dp[j7] : 0);
            
            // 30-day pass cost
            int after30 = days[i] + 29;
            auto it30 = upper_bound(days.begin() + i, days.end(), after30);
            int j30 = it30 - days.begin();
            int opt3 = costs[2] + (j30 < n ? dp[j30] : 0);
            
            dp[i] = min({opt1, opt2, opt3});
        }
        
        return dp[0];
    }
};