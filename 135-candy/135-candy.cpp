class Solution {
public:
    int candy(vector<int>& r) {
        int n = r.size();
        vector<int> candy(n,1);
        
        for(int i = 1; i < n; i++)
        {
            if(r[i] > r[i-1])
                candy[i] = candy[i-1]+1;
        }
        int sum = candy[r.size() - 1];
        for (int i = r.size() - 2; i >= 0; i--) {
            if (r[i] > r[i + 1]) {
                candy[i] = max(candy[i], candy[i + 1] + 1);
            }
            sum += candy[i];
        }
        return sum;
    }
};