class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();

        unordered_map<char, int> mp;
        int j = 0;
        int res = 0;

        for(int i = 0; i < n; i++){
            int currChar = s[i];

            if(mp.find(currChar) != mp.end()){
                j = max(mp[currChar], j);
            }

            int currDist = i-j+1;

            res = max(res, currDist);

            mp[currChar] = i+1;
        }

        return res;
    }
};