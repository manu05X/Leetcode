class Solution {
public:
    int countHomogenous(string s) {
        int ans = 0;
        int currStreak = 0;
        int MOD = 1e9 + 7;
        
        for (int i = 0; i < s.size(); i++) {
            if (i == 0 || s[i] == s[i - 1]) {
                currStreak++;
            } else {
                currStreak = 1;
            }
            
            ans = (ans + currStreak) % MOD;
        }
        
        return ans;
    }
};
/*
"abbcccaa"
a = 1
b = 1,2
c = 1,2,3
a = 1,2

curr = 1,1,2,1,2,3,1,2
ans =  1,2,4,5,7,10,11,13
*/