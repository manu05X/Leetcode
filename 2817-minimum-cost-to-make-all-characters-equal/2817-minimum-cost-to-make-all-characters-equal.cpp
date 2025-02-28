class Solution {
public:
    long long minimumCost(string s) {
        int n = s.size();
        long long totalCost = 0;
        
        for (int i = 1; i < n; i++) {
            if (s[i] != s[i - 1]) {
                totalCost += min(i, n - i); // Choose min flip cost
            }
        }
        
        return totalCost;
    }
};