class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        
        string prefix = strs[0];
        
        for (int i = 1; i < strs.size(); i++) {
            int j = 0;
            // Compare characters until the end of current string or prefix
            while (j < strs[i].size() && j < prefix.size() && strs[i][j] == prefix[j]) {
                j++;
            }
            prefix = prefix.substr(0, j);
            
            // Early exit if prefix becomes empty
            if (prefix.empty()) break;
        }
        
        return prefix;
    }
};