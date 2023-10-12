class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        //map of string and vector<string>
        unordered_map<string, vector<string> > m;
        vector<vector<string>> ans;

        // add string to map
        for(auto str : strs){
            string s = str;
            // sort the string i.e s
            sort(s.begin(), s.end());
            //push_back map with key s and value from str
            m[s].push_back(str);
        }

        for(auto x : m){
            ans.push_back(x.second);
        }

        return ans;
    }
};