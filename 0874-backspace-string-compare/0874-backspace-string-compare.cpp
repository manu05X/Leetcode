class Solution {
public:
    string compression(string s){
        stack<char> st;

        for(char c : s){
            if(c == '#'){
                if(!st.empty()){
                    st.pop();
                }
            } else {
                st.push(c);
            }
        }

        string res = "";
        while(!st.empty()){
            res += st.top();
            st.pop();
        }

        reverse(res.begin(), res.end()); // Because we popped in reverse order
        return res;
    }

    bool backspaceCompare(string s, string t) {
        string sc = compression(s);
        string tc = compression(t); 
        return sc == tc;
    }
};


