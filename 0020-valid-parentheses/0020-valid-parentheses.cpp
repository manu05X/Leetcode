class Solution {
public: 
    bool isValid(string s) {
        stack<char> st;
        for (char c : s) { 
            if (c == '(') 
                st.push(')');
            else if (c == '{')
                st.push('}'); 
            else if (c == '[') 
                st.push(']');
            else {
                if (st.empty() || st.top() != c) // Check if stack is empty before accessing top
                    return false;
                st.pop(); // Pop after comparing
            }
        }
        return st.empty(); // Ensure no unmatched open brackets remain
    }
};




/*
class Solution {
public:
    bool isValid(string s) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        
        stack<int> st;
        int n = s.size();

        if(n == 1){
            return false;
        }
        if(n == 0){
            return true;
        }

        for(int i = 0; i < n; i++){
            char ch = s[i];

            if(ch == ')' || ch == '}' || ch == ']'){
                if(st.empty()){
                    return false;
                }
                if(ch == '}' && st.top() != '{')
                    return false;
                if(ch == ')' && st.top() != '(')
                    return false;
                if(ch == ']' && st.top() != '[')
                    return false;
                //else it must be a valid conndition | () or {} or [] |
                st.pop();
            }
            else
            {
                st.push(ch);
            }
        }

        return st.empty()?true : false;
    }
};
*/