class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int ans = 0;
        
        unordered_map<char,int> mp;
        int j = 0;
        for(int i = 0; i < n; i++)
        {
            if(mp.find(s[i]) != mp.end())
            {
                j = max(mp[s[i]], j);
            }
            
            ans = max(ans, i-j+1);
            mp[s[i]] = i+1;
        }
        
        return ans;
    }
};