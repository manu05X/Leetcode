class Solution {
public:
    double average(vector<int>& salary) {
        double maxE = INT_MIN;
        double minE = INT_MAX;
        
        double ans = 0;
        for(int i = 0; i < salary.size(); i++)
        {
            maxE = max(maxE, (double)salary[i]);
            minE = min(minE, (double)salary[i]);
            
            ans += salary[i];
        }
        ans = (ans-(maxE+minE));
        int n = salary.size() - 2;
        return ans/n;
    }
};