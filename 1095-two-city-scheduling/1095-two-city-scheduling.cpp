class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        //[[10,20],[30,200],[400,50],[30,20]]
        int n = costs.size()/2;
        int cost = 0;
         // Sort by a gain which company has 
        // by sending a person to city A and not to city B
        sort(costs.begin(), costs.end(),[](const vector<int> &a, const vector<int> &b){
            return (a[1]-a[0] > b[1]-b[0]);
        });
        //{{30, 200}, {10, 20}, {30, 20}, {400, 50}}

        // To optimize the company expenses,
    // send the first n persons to the city A
    // and the others to the city B
        for(int i =0; i < n; i++)
        {
            cost += costs[i][0] + costs[i + n][1];
        }

        return cost;
    }
};