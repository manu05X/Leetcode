class Solution {
public:
    vector<string> letterCasePermutation(string s) {
        vector<string> ans;
        dfs(s,0, ans);
        return ans;
    }

    void dfs(string s,int idx, vector<string>& ans) {
        // Base case: If the end of the array is reached, add the current permutation to the list
        if (idx >= s.size()) {
            ans.push_back(s);
            return;
        }
        
        // Recursively call the method to handle the next character without modification
        dfs(s,idx + 1,ans);

        // If the current character is a letter, toggle its case and recurse
        if (isalpha(s[idx])) {
            s[idx] ^= ' ';
           dfs(s,idx + 1,ans);
            s[idx] ^= ' '; // Revert the change for backtracking
        }
    }
};
