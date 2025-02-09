class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> a(26), b(26);
        for (auto c : s) ++a[c-'a'];
        for (auto c : t) ++b[c-'a'];
        int ans = 0;
        for (int i=0; i<26; ++i) {
            ans += abs(a[i] - b[i]);
        }
        return ans;
    }
};


/*
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

*/
