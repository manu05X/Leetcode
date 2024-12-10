class Solution {
public:
    int maximumLength(string s) {
        int n = s.size();
        map<string, int> mp;

        for(int left = 0; left < n; left++){
            string currString;
            for(int right = left; right < n; right++){
                if(currString.empty() or currString.back() == s[right]){
                    currString.push_back(s[right]);
                    mp[currString]++;
                } else {
                    break;
                }
            }
        }


        int ans = 0;
        for(auto it : mp){
            string str = it.first;

            if(it.second >= 3 && str.size() > ans){
                ans = str.size();
            } 
        }

        return ans == 0 ? -1 : ans;
    }
};