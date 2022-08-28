class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0, l = INT_MAX;
        for(int x : prices)
        {
            l = min(l,x);
            res = max(res, x-l);
        }
        return res;
    }
};