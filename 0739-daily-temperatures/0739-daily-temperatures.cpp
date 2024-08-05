class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int n = t.size();
        vector<int> ans(n, 0);

        for (int currDay = n - 2; currDay >= 0; currDay--) {
            int futureDay = currDay + 1;

            while (futureDay < n && t[currDay] >= t[futureDay]) {
                if (ans[futureDay] == 0) {
                    futureDay = n;
                    break;
                }
                futureDay += ans[futureDay];
            }

            if (futureDay < n) {
                ans[currDay] = futureDay - currDay;
            }
        }

        return ans;
    }
};