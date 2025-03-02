class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();

        vector<vector<int>> compCost(n+1, vector<int>(m+1, 0));

        // Fill in the base case values
        for(int i = 1; i <= n; i++){
            compCost[i][0] = compCost[i-1][0] + s1[i-1];  // Correct initialization for s1
        }

        for(int j = 1; j <= m; j++){
            compCost[0][j] = compCost[0][j-1] + s2[j-1];  // FIXED: Use s2[j-1] instead of s1[j-1]
        }

        // Fill the remaining cells using DP
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(s1[i-1] == s2[j-1]){
                    compCost[i][j] = compCost[i-1][j-1];  // No cost if characters match
                } else {
                    compCost[i][j] = min(
                        s1[i-1] + compCost[i-1][j],  // Delete from s1
                        s2[j-1] + compCost[i][j-1]   // Delete from s2
                    );
                }
            }
        }

        // Return the answer for the entire input strings
        return compCost[n][m];
    }
};
