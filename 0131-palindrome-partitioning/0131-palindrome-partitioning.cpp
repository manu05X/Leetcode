class Solution {
public:
    bool isPalindrome(const string& s, int start, int end){
        while (start < end) {
            if (s[start++] != s[end--]) return false;
        }
        return true;
    }

    // Backtracking function
    void dfs(int start, string& s, vector<string>& path, vector<vector<string>>& ans){
        if(start == s.size()){
            ans.push_back(path);
        }

        for(int end = start; end < s.size(); end++){
            if(isPalindrome(s, start, end)){
                path.push_back(s.substr(start, end - start + 1));
                dfs(end+1, s, path, ans);
                path.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> path;
        dfs(0, s, path, ans);
        return ans;
    }
};



/*
class Solution {
public:
    // Function to find all possible partitions of the given string s
    vector<vector<string>> partition(string s) {
        int len = s.length(); // Length of the input string
        vector<vector<bool>> dp(len, vector<bool>(len, false)); // DP table to store whether substring(i, j) is a palindrome or not
        vector<vector<string>> result; // Vector to store all possible partitions
        
        // Recursive function to explore all possible partitions starting from 'start'
        dfs(result, s, 0, {}, dp);
        
        return result; // Return the final result
    }

    // Depth-first search function to explore all possible partitions
    void dfs(vector<vector<string>>& result, string s, int start, vector<string> currentList, vector<vector<bool>>& dp) {
        if (start >= s.length()) {
            result.push_back(currentList); // Add current partition to the result if 'start' reaches end of string
            return;
        }
        
        // Iterate from 'start' to end of string
        for (int end = start; end < s.length(); end++) {
            // Check if substring(s[start:end]) is a palindrome
            if (s[start] == s[end] && (end - start <= 2 || dp[start + 1][end - 1])) {
                dp[start][end] = true; // Update DP table
                
                // Add substring(s[start:end]) to current partition list
                currentList.push_back(s.substr(start, end - start + 1));
                
                // Recursively explore partitions starting from next character
                dfs(result, s, end + 1, currentList, dp);
                
                // Backtrack: Remove the last added substring from current partition list
                currentList.pop_back();
            }
        }
    }
};
*/