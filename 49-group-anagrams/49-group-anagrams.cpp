class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mp;
        for(string s : strs)
        {
            string t = s;
            sort(t.begin(), t.end());// Sorting the string
            mp[t].push_back(s); // Sorted string is the key and the value is the initial string
        }
        vector<vector<string>> ans;
        for(auto p : mp)
        {
            ans.push_back(p.second); // Traversing the map and adding the vectors of string to ans
        }
        
        return ans;
    }
};