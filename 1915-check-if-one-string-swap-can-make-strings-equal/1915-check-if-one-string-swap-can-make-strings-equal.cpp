class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();

        if(n != m) return false;

        vector<int> freq(26,0);
        int numDiff = 0;

        for(int i = 0; i < n; i++){
            if(s1[i] != s2[i]){
                numDiff++;
                
                if(numDiff > 2){
                    return false;
                }
            }

            freq[s1[i]-'a']++;
            freq[s2[i]-'a']--;
        }

        int count = 0;
        for(int i = 0; i < 26; i++){
            if(freq[i] != 0){
                count++;
            }
        }

        if(count <= 1){
            return true;
        } else {
            return false;
        }
    }
};