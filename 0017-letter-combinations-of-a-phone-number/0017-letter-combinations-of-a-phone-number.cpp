class Solution {
public:
    void dfs(string digits, vector<string>& ans, string &tmp, vector<string>& pad, int idx){
        // If the path is the same length as digits, we have a complete combination
        if(idx == digits.size()){
            ans.push_back(tmp);
            return;// Backtrack
        }

        // Get the letters that the current digit maps to, and loop through them
        // { 0,  1,  2  ,  3   ,    4  ,   5  ,   6  ,    7  ,    8 ,   9   };
        // {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        string currValue = pad[digits[idx]-'0']; 
        for(int i = 0; i < currValue.size(); i++){
            // Add the letter to our current path
            tmp.push_back(currValue[i]);
            // Move on to the next digit
            dfs(digits,ans,tmp,pad,idx+1);
            // Backtrack by removing the letter before moving onto the next
            tmp.pop_back();
        }
    }
    
    vector<string> letterCombinations(string digits) {
        if(digits.empty()){
            return {};
        }

        vector<string> pad = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> ans;
        string temp;
        // Initiate backtracking with an empty path and starting index of 0
        dfs(digits,ans,temp,pad,0);

        return ans;
    }
};