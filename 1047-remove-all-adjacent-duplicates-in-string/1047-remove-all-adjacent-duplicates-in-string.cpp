class Solution {
public:
    string removeDuplicates(string s) {
        string ans = "";
        stack<int> st, st1;
        st.push(s[0]);
        
        for(int i = 1; i < s.size(); i++)
        {
            if(!st.empty() && st.top() == s[i])
            {
                st.pop();
            }
            else if(!st.empty() && st.top() != s[i])
            {
                st.push(s[i]);
            }
            else
            {
                st.push(s[i]);
            }
        }
        
        while(!st.empty())
        {
            st1.push(st.top());
            st.pop();
        }
        
        while(!st1.empty())
        {
            ans += st1.top();
            st1.pop();
        }
        
        return ans;
    }
};