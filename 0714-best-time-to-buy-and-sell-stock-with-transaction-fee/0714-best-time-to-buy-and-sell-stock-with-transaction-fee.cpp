class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        if (n == 0) return 0;

        int noStockProfit = 0;  // Max profit when not holding a stock
        int holdProfit = -prices[0];  // Max profit when holding a stock

        for (int i = 1; i < n; ++i) {
            // If we sell today, we get prices[i] but pay the fee
            noStockProfit = max(noStockProfit, holdProfit + prices[i] - fee);
            
            // If we buy today, we spend prices[i]
            holdProfit = max(holdProfit, noStockProfit - prices[i]);
        }
        
        return noStockProfit;  // Final profit when we are not holding a stock
    }
};
