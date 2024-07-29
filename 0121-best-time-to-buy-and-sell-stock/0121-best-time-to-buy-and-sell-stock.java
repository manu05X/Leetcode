public class Solution {
    public int maxProfit(int prices[]) 
    {
        int minPrice = prices[0];
        int maxProfit = 0;
        for (int i = 0; i < prices.length; i++) 
        {
             // Update max_profit if the difference between current price and min_price is greater than current max_profit
            maxProfit = Math.max(maxProfit, prices[i]-minPrice);
            // Update min_price if the current price is less than the current min_price
            minPrice = Math.min(prices[i], minPrice);
            // if (prices[i] < minprice)
            //     minprice = prices[i];
            // else if (prices[i] - minprice > maxprofit)
            //     maxprofit = prices[i] - minprice;
        }
        return maxProfit;
    }
}