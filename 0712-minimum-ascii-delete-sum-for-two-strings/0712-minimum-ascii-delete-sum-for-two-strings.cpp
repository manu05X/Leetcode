class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();

        vector<vector<int>> compCost(n+1, vector<int>(m+1, 0));

        // Fill in the base case values
        for(int i = 1; i <= n; i++){
            compCost[i][0] = compCost[i-1][0] + s1[i-1];
        }

        for(int j = 1; j <= m; j++){
            compCost[0][j] = compCost[0][j-1] + s2[j-1];
        }

        // Fill the remaining cells using the Bellman Equation
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(s1[i-1] == s2[j-1]){
                    compCost[i][j] = compCost[i-1][j-1];
                } else {
                    compCost[i][j] = min(s1[i-1] + compCost[i-1][j], s2[j-1] + compCost[i][j-1]);
                }
            }
        }

        // Return the answer for entire input strings
        return compCost[n][m];
    }
};