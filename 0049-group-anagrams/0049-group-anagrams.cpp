class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        
        unordered_map<string, vector<string> > m;
        vector<vector<string>> ans;

        for(auto str : strs){
            string s = str;
            sort(s.begin(), s.end());
            m[s].push_back(str);
        }

        for(auto x : m){
            ans.push_back(x.second);
        }

        return ans;
    }
};