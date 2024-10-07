#include <bits/stdc++.h>
class Solution {
public:
    string removeDuplicates(string s) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        stack<char> st;

        for(int i =0; i < s.size(); i++)
        {
            char t = s[i];

            if(!st.empty() && t == st.top()){
                st.pop();
            }
            else{
                st.push(t);
            }
        }

        string ans = "";

        while(!st.empty()){
            ans = st.top()+ans;
            st.pop();
        }
        //reverse(ans.begin(), ans.end());
        return  ans;
    }
};