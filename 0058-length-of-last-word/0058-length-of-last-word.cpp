class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.size();
        int p = n-1;
        while(p >= 0 && s[p] == ' '){
            p--;
        }

        int length = 0;
        while(p >= 0 && s[p] != ' '){
            p--;
            length++;
        }
        return length;
    }
};