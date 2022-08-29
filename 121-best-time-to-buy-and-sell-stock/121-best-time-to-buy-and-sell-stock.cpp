class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0, l = INT_MAX;
        for(int x : prices)
        {
            if(x < l)
            {
                l = x;
            }
            else if(x-l > res)
            {
                res = x-l;
            }
        }
        return res;
    }
};