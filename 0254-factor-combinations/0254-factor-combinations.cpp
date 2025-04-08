class Solution {
public:
    void dfs(int start, int n, vector<int>& path, vector<vector<int>>& ans) {
        if (n == 1) {
            if (path.size() > 1) { // Only add if more than one factor
                ans.push_back(path);
            }
            return;
        }

        // Loop from current number to n
        for (int i = start; i <= n; i++) {
            if(n%i == 0){
                path.push_back(i);         // Choose number
                dfs(i , n/i, path, ans); // allow reuse of same factor
                path.pop_back();           // Backtrack
            }
        }
    }

    vector<vector<int>> getFactors(int n) {
        ios_base::sync_with_stdio(false);  
        cin.tie(NULL);
        
        if(n == 1){
            return {};
        }

        vector<vector<int>> ans;
        vector<int> path;
        dfs(2, n, path, ans);
        return ans;
    }
};