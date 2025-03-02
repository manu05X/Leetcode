class Solution {
public:
     int maxProfit(vector<int>& prices) {
        // Initialize the profit states:
        // f0: the max profit we can have at this state if we don't hold a stock
        // f1: the max profit we can have at this state if we hold one stock
        // holdProfit: stores the previous f0 state to calculate the new f1 state
        int noStockProfit = 0;
        int holdProfit = 0; 
        int oneStockProfit = -prices[0]; // Assume we bought the first stock

        // Loop through the list of prices starting from the second price
        for (int i = 1; i < prices.size(); ++i) {
            // Calculate the max profit if we don't hold a stock today
            // either we did not hold a stock yesterday (noStockProfit) or
            // we sold the stock we were holding (oneStockProfit + prices[i]).
            int newNoStockProfit = max(noStockProfit, oneStockProfit + prices[i]);
          
            // Calculate the max profit if we hold one stock today
            // either we were already holding a stock (oneStockProfit) or
            // we buy a new stock today (holdProfit - prices[i]).
            oneStockProfit = max(oneStockProfit, holdProfit - prices[i]);
          
            // Update holdProfit to the previous noStockProfit at the end of the day 
            holdProfit = noStockProfit;
            // Update noStockProfit to the new calculated noStockProfit
            noStockProfit = newNoStockProfit;
        }
        // Since we want to maximize profit, we should not hold any stock at the end
        // hence we return noStockProfit which represents the max profit with no stock in hand
        return noStockProfit;
    }
};