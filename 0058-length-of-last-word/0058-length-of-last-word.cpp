class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.size(), length = 0;
        int p = n;
        while(p > 0){
            p--;
            if(s[p] != ' '){
                length++;
            }
            else if(length > 0){
                return length;
            }
        }
        return length;
    }
};