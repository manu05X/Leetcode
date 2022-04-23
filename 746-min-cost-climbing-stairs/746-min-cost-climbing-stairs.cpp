class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> minCost(cost.size()+1,0);
        
        for(int i = 2; i < minCost.size(); i++)
        {
            int oneStep = minCost[i-1] + cost[i-1];
            int twoStep = minCost[i-2] + cost[i-2];
            
            minCost[i] = min(oneStep, twoStep);
        }
        
        return minCost[minCost.size()-1];
    }
};