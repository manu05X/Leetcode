class Solution {
    public int maxProfit(int[] prices) {
        int n = prices.length;
        int currProfit = 0;
        int Profit = 0;

        int minima = prices[0];
        for(int i = 1; i < n; i++){
            minima = Math.min(minima, prices[i]);
            currProfit = Math.max(currProfit, prices[i]-minima);
            Profit = Math.max(currProfit, Profit);
        }

        return Profit;
        
    }
}