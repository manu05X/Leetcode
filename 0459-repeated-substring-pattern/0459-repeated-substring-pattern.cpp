class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string t = s+s;
        string tmp = t.substr(1,t.size()-2);
        if(tmp.find(s)!= -1){
            return true;
        }
        return false;
    }
};