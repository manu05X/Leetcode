class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> freq(26,0);

        for(int i = 0; i < s.size(); i++){
            freq[s[i]-'a']++;
        }

        for(int i = 0; i < t.size(); i++){
            freq[t[i]-'a']--;
        }

        int minStep = 0;
        for(int x : freq){
            minStep += abs(x);
        }

        return minStep;
    }
};