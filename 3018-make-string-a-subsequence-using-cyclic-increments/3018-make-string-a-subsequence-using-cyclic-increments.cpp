class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int p2 = 0;
        int n = str1.size();
        int m = str2.size();

        for(int p1 = 0; p1 < n && p2 < m; p1++){
            if(str1[p1] == str2[p2] || 
            (str1[p1]+1 == str2[p2]) || (str1[p1]-25 == str2[p2])){
                p2++;
            }
        }

        return p2 == m;
    }
};