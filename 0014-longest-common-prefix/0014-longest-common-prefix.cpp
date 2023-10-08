class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
       int s = strs[0].size();
       int n = strs.size();
       
       for(int i = 1; i < n; i++)
       {
           int j = 0;
           while(j < strs[i].size() && strs[i][j]==strs[0][j]){
               j++;
           }

           s = min(s,j);
       }
       return strs[0].substr(0, s);
    }
};