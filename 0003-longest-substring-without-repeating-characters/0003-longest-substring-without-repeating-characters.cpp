class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int ans = 0;
        //map for keeping currChar index or last occurance of it
        unordered_map<char, int> mp;
        //last index of unique charter window
        int left = 0; 

        for(int right = 0; right < n; right++){
            int currChar = s[right]; // current Character

            //Checking the map if it contains the currChar
            if(mp.find(currChar) != mp.end())
            {
                //updating left index as previous range has repeting char
                left = max(mp[currChar],left); 
            }
            //current range of unique charter
            int currDiff = (right - left +1);
            ans = max(currDiff, ans);
            //adding the currChar in map
            mp[currChar] = right+1;
        }

        return ans;
    }
};

/*
abcabcbb
01234567

currDist = (r-l+1)

l = 0, r = 0, currDist = 1, ans = 1, mp{a:1}
l = 0, r = 1, currDist = 2, ans = 1, mp{a:1, b:2}
l = 0, r = 2, currDist = 3, ans = 3, mp{a:1, b:2, c:3}
l = 1, r = 3, currDist = 3, ans = 3, mp{a:4, b:2, c:3}, as a is repeting so change the left to where it was previously found i.e 1
l = 2, r = 4, currDist = 3, ans = 3, mp{a:4, b:5, c:3} similarly for b=5, l = 2
l = 3, r = 5, currDist = 3, ans = 3, mp{a:4, b:5, c:6} similarly for c=6, l = 3
l = 5, r = 6, currDist = 2, ans = 3, mp{a:4, b:6, c:6} similarly for b=6, l = 5
l = 7, r = 7, currDist = 1, ans = 3, mp{a:4, b:7, c:6} similarly for b=6, l = 7

*/