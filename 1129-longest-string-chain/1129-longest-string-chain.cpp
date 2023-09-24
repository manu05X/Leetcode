class Solution {
public:
    static bool compare(const string &s1, const string &s2){
        return s1.length() < s2.length();
    }

    int longestStrChain(vector<string>& words) 
    {
        sort(words.begin(), words.end(),compare);

        unordered_map<string, int> mp;
        int res = 1;

        for(string w : words)
        {
            for(int i = 0; i < w.length(); i++){
                string pre = w.substr(0,i) + w.substr(i+1);

                //mp[w] = max(mp[w], mp.find(pre) == mp.end() ? 1 : mp[pre] + 1);

                if (mp.find(pre) != mp.end()) 
                {
                    mp[w] = max(mp[w], mp[pre] + 1);
                }
                else
                {
                    mp[w] = max(mp[w], 1);
                }
            }
            res = max(res, mp[w]);
        }
        return res;
    }  
};