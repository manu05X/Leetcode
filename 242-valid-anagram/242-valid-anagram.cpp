class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size())
            return false;
        
        int cntr[26]={0};
        for(int i = 0; i < s.size(); i++)
        {
            cntr[s[i]-'a']++;
            cntr[t[i]-'a']--;
        }
        
        for(int c : cntr)
        {
            if(c != 0)
                return false;
        }
        return true;
    }
};