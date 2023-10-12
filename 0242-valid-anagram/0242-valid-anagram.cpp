class Solution {
public:
    bool isAnagram(string s, string t) {
        int ns = s.size();
        int nt = t.size();
        // 26 alphabet char hashMap
        vector<int> hs(26,0);
        if(ns != nt){
            return false;
        }
        //filling the hashMap with frequency of charter in s
        for(int i = 0; i < ns; i++){
            hs[s[i]-'a']++;
        }
        //cheking other string that is t's no of character in hashmap
        for(int i = 0; i < nt; i++){
            hs[t[i]-'a']--;
            if (hs[t[i] - 'a'] < 0)
            {
                 return false;
            }
        }
        return true;
    }
};