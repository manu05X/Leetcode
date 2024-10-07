/*
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
*/
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int n = t.size();
        vector<int> ans(n, 0);

        int* st = new int[n];
        int top = -1;

        for (int currDay = 0; currDay < n; currDay++) 
        {
            while (top >= 0 && t[currDay] > t[st[top]]) {
                int pastIdx = st[top];
                ans[pastIdx] = currDay - pastIdx;
                top--;
            }

            top++;
            st[top] = currDay;

        }

        return ans;
    }
};