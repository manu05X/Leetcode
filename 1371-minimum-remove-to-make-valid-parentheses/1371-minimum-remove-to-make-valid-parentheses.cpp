class Solution {
public:
    string minRemoveToMakeValid(string s) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        
        stack<pair<char,int>> st;
        //string ans = s;
        string res = "";

        for(int i = 0; i < s.size(); i++){
            char ch = s[i];
            if(!st.empty() && st.top().first == '(' && ch == ')'){
                st.pop();
            }
            else if(ch == '(' || ch == ')'){
                st.push({ch,i});
            }
        }

         // Remove the invalid parentheses
        while (!st.empty()) {
            s[st.top().second] = '#';
            st.pop();
        }

        // making the resultant string by excluding '#'
        for (int i = 0; i < s.length(); ++i)
        {
            if (s[i] != '#')
                res.push_back(s[i]);
        }
        return res;
    }
};