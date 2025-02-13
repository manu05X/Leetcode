class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int n = g.size();
        int m = s.size();

        int p1 = 0;
        int p2 = 0;

        sort(s.begin(), s.end());
        sort(g.begin(), g.end());

        while(p1 < n && p2 < m){
            if(s[p2] >= g[p1]){
                p1++;
            }

            p2++;
        }

        return p1;
    }
};