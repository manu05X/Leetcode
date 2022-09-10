class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int prevMin = prices[0];
        for(int i = 1; i < prices.size(); i++)
        {
            if(prices[i]-prevMin > 0)
            {
                ans += prices[i]-prevMin;
                prevMin=prices[i];
            }
            else if(prices[i] < prevMin){
                prevMin = prices[i];
            }
        }
        return ans;
    }
};