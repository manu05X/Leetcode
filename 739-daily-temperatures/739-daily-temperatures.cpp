class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        int n = temp.size();
        vector<int> ans(n,0);
        
        int hotest = 0;
        for(int i = n-1; i >= 0; i--)
        {
            int curr = temp[i];
            if(curr >= hotest)
            {
                hotest = curr;
                continue;
            }
            
            int days = 1;
            while(temp[i+days] <= curr)
            {
                days += ans[i+days];
            }
            ans[i] = days;
        }
        
        return ans;
    }
};