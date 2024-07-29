func maxProfit(prices []int) int {
    n := len(prices)
    if n == 0 {
        return 0
    }

    minPrice := prices[0]
    maxProfit := 0

    for i := 1; i < n; i++ {
        if prices[i] - minPrice > maxProfit {
            maxProfit = prices[i] - minPrice
        }
        if prices[i] < minPrice {
            minPrice = prices[i]
        }
    }

    return maxProfit
}