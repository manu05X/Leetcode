class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n = s.size();
        int m = t.size();

        if(n!=m){
            return false;
        }
        vector<int> freq1(128, -1);
        vector<int> freq2(128, -1);

        for(int i = 0; i<s.size(); i++){
            //int x = s[i];
            //int y = t[i];
            if(freq1[s[i]] != freq2[t[i]]){
                return false;
            }

            freq1[s[i]] = i;
            freq2[t[i]] = i;
        }
        return true;
    }
};