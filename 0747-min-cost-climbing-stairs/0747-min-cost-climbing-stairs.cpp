class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int downOne = 0;
        int downTwo = 0;

        for(int i = 2; i < n+1; i++){
            int temp = downOne;
            downOne = min(downOne + cost[i-1], downTwo+cost[i-2]);
            downTwo = temp;
        }

        return downOne;
    }
};