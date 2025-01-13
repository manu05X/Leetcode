class Solution {
public:
    int minimumLength(string s) {
        int n = s.size();
        vector<int> charFreq(26,0);

        for(char x : s){
            charFreq[x-'a']++;
        }

        int ans = 0;
        for(int freq : charFreq){
            if(freq == 0){
                continue;
            } else if(freq % 2 == 0){
                ans += 2;
            } else {
                ans += 1;
            }
        }

        return ans;
    }
};