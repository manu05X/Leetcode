class Solution {
public:
    string removeDuplicates(string s, int k) {
        int n = s.size();
        stack<pair<char,int>> st;

        for(int i = 0; i < n; i++){
            char curr = s[i];

            if(!st.empty())
            {
                if(st.top().first == curr)
                {
                    st.top().second += 1;
                    if(st.top().second % k == 0)
                    {
                        st.pop();
                    }
                }
                else{
                    st.push({curr, 1});
                }
            }
            else{
                st.push({curr, 1});
            }
        }

        string ans = "";
        while(!st.empty())
        {
            ans = string(st.top().second, st.top().first)+ans;
            st.pop();
        }

        return ans;
    }
};