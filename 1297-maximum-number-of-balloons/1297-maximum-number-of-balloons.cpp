class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int n = text.size();
        string s = "ballon";

        unordered_map<char, int> mp;
        for(auto x : s){
            mp[x] = 0;
        }

        for(auto x : text){
            if(mp.count(x)){
                mp[x]++;
                //ans = min(ans, mp[x]);
            }
        }

        // Since 'l' and 'o' appear twice in "balloon", we divide their counts by 2
        mp['l'] /= 2;
        mp['o'] /= 2;

        // The number of "balloon"s we can form is determined by the minimum count among the characters
        int ans = INT_MAX;
        ans = min(ans, mp['b']);
        ans = min(ans, mp['a']);
        ans = min(ans, mp['l']);
        ans = min(ans, mp['o']);
        ans = min(ans, mp['n']);

        return ans;
    }
};



/*
class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int n = text.size();
        string s = "ballon";

        unordered_map<char, int> mp;
        for(auto x : s){
            mp[x] = 0;
        }

        int ans = INT_MAX;

        for(auto x : text){
            if(mp.count(x)){
                mp[x]++;
                //ans = min(ans, mp[x]);
            }
        }

        for(auto x : mp){
            ans = min(x.second, ans);
            if(x.first == 'l' && x.second == 1){
                ans = 0;
            }
            if(x.first == 'o' && x.second == 1){
                ans = 0;
            }
        }

        return ans;
    }
};

*/