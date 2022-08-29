class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0, l = INT_MAX;
        for(int i = 0; i < prices.size(); i++)
        {
            if(prices[i] < l)
            {
                l = prices[i];
            }
            else if(prices[i]-l > res)
            {
                res = prices[i]-l;
            }
        }
        return res;
    }
};