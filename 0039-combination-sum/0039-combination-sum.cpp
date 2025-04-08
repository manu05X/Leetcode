class Solution {
public:
    void dfs(int idx, vector<int>& candidates, int target, vector<int>& path, vector<vector<int>>& ans) {
        if(target == 0){
            ans.push_back(path);
            return;
        }

        if(target < 0 || idx >= candidates.size()){
            return;
        }

        path.push_back(candidates[idx]);
        dfs(idx, candidates, target-candidates[idx], path, ans); // Not moving forward, allow same element
        path.pop_back(); // Backtrack

        // Skip the number
        dfs(idx+1, candidates, target, path, ans); // Move to next

    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;

        dfs(0, candidates, target, temp, ans);

        return ans;
    }
};


/*
class Solution {
public:
    void backtrack(vector<int>& candidates, vector<vector<int>>& ans, vector<int>& subset,int remain, int start){
        if(remain < 0){
            return; // If remain becomes negative, terminate the current branch of the backtracking
        }else if(remain == 0){
             ans.push_back(subset); // If remain is zero, add the current combination to the result
        }
        else{
            for(int i = start; i < candidates.size(); i++){
                subset.push_back(candidates[i]); // Choose the current candidate
                backtrack(candidates, ans, subset, remain - candidates[i], i); // Recursively backtrack with updated remain
                subset.pop_back(); // Remove the last element to backtrack
            }
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> subset;
        sort(candidates.begin(), candidates.end()); // Sort the candidates vector
        backtrack(candidates, ans, subset, target, 0);

        return ans;
    }
};
*/