class Solution {
public:
    void backtrack(vector<int>& candidates, int target, int start, vector<int>& path, vector<vector<int>>& result) {
        // Base case: If the target is reached, add the current combination to the result
        if (target == 0) {
            result.push_back(path);
            return;
        }

        //int prevElm = INT_MIN; 

        // Iterate through the candidates starting from the 'start' index
        for (int i = start; i < candidates.size(); ++i) {
            // Skip duplicates to avoid duplicate combinations
            // This checks if the current element is the same as the previous one, and if it is, it skips it, but only when i > start.
            if (i > start && candidates[i] == candidates[i - 1]) {
                continue;
            }

            //if(candidates[i] == prevElm) continue;

            // Check if the current candidate can be included in the combination
            if (candidates[i] <= target) {
                // Add the current candidate to the combination
                path.push_back(candidates[i]);
                // Recursively explore further combinations with the remaining target
                backtrack(candidates, target - candidates[i], i + 1, path, result);
                // Backtrack: Remove the last added candidate to try other combinations
                path.pop_back();
            }

            //prevElm = candidates[i];
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        ios_base::sync_with_stdio(false);  
        cin.tie(NULL);
        
        vector<vector<int>> result;
        vector<int> path;
        // Sort the candidates to handle duplicates efficiently
        sort(candidates.begin(), candidates.end());
        // Start backtracking from the beginning
        backtrack(candidates, target, 0, path, result);
        return result;
    }
};