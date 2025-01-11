class Solution {
public:
    vector<int> count(const string& word) {
        vector<int> ans(26, 0);
        for (char c : word) {
            ans[c - 'a']++;
        }
        return ans;
    }

    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int> bmax(26,0);
        for(const string& b : words2){
            vector<int> bCount = count(b);
            for(int i = 0; i < 26; i++){
                bmax[i] = max(bmax[i], bCount[i]);
            }
        }


        vector<string> ans;
        for(const string& c : words1){
            vector<int> aCount = count(c);
            bool isUniversal = true;
            for(int i = 0; i < 26; i++){
                if(aCount[i] < bmax[i]){
                    isUniversal = false;
                    break;
                }
            }

            if(isUniversal){
                ans.push_back(c);
            }
        }

        return ans;
    }
};