class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // ios_base::sync_with_stdio(false);
        // cin.tie(NULL);
        // cout.tie(NULL);

        // //map of string and vector<string>
        // unordered_map<string, vector<string> > m;
        // vector<vector<string>> ans;

        // // add string to map
        // for(auto str : strs){
        //     string s = str; // eat
        //     // sort the string i.e s
        //     sort(s.begin(), s.end());//key
        //     //push_back map with key s and value from str
        //     m[s].push_back(str);//value
        // }
        // // key -> value

        // for(auto x : m){
        //     ans.push_back(x.second);
        // }

        // return ans;
        unordered_map<string, vector<string>> mp;
        vector<vector<string>> ans;
        for(int i = 0;i< strs.size();i++) {
            string s = strs[i];
            sort(s.begin(), s.end());
            mp[s].push_back(strs[i]);
        }
        for(auto m : mp) {
            ans.push_back(m.second);
        }
        return ans;
    }
};

/*
key --> value
["abt"] = {"bat"}, 
["ant"] = {"tan", "nat"}, 
["aet"] = {"eat", "tea", "ate"}}
*/