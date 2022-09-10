class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minCurr = INT_MAX;
        int profit = 0;
        
        for(int i = 0; i < prices.size(); i++)
        {
            if(prices[i] < minCurr)
            {
                minCurr = prices[i];
            }
            else if(prices[i]-minCurr > profit)
            {
                profit = prices[i]-minCurr;
            }
        }
        
        return profit;
    }
};