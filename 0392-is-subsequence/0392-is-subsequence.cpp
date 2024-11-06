class Solution {
public:
    bool isSubsequence(string s, string t) {
        int ns = s.size();
        int nt = t.size();
        int p1 = 0, p2 = 0;

        while(p1 < ns && p2 < nt)
        {
            if(s[p1] == t[p2]){
                p1++;
            }
            p2++;
        }

        return p1 == ns;
    }
};