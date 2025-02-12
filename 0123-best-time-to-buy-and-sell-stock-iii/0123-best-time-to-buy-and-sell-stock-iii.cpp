class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int firstBuy = INT_MAX, secondBuy = INT_MIN;
        int firstProfit = 0 , secondProfit = 0;

        for(auto i : prices) {
            // the maximum profit if only one transaction is allowed
           firstBuy = min(i, firstBuy);
           firstProfit = max(firstProfit, i - firstBuy);

           // re-invest the gained profit in the second transaction
           secondBuy = max(secondBuy, firstProfit - i);
           secondProfit = max(secondProfit, i + secondBuy );
        }
        return secondProfit;
    }
};




/*

class Solution {
  public:
  int maxProfit(vector<int>& prices) {
    int length = prices.size();
    if (length <= 1) return 0;

    int leftMin = prices[0];
    int rightMax = prices[length - 1];

    vector<int> leftProfits(length, 0);
    // pad the right DP array with an additional zero for convenience.
    vector<int> rightProfits(length + 1, 0);

    // construct the bidirectional DP array
    for (int l = 1; l < length; ++l) {
      leftProfits[l] = max(leftProfits[l - 1], prices[l] - leftMin);
      leftMin = min(leftMin, prices[l]);

      int r = length - 1 - l;
      rightProfits[r] = max(rightProfits[r + 1], rightMax - prices[r]);
      rightMax = max(rightMax, prices[r]);
    }

    int maxProfit = 0;
    for (int i = 0; i < length; ++i) {
      maxProfit = max(maxProfit, leftProfits[i] + rightProfits[i + 1]);
    }
    return maxProfit;
  }
};

*/