class Solution {
public:

    string compression(string s){
        stack<char> st;

        for(int i = 0; i < s.size(); i++){
            if(s[i] == '#'){
                st.pop();
            }
            else{
                st.push(s[i]);
            }
        }

        string res = "";

        while(!st.empty()){
            res += st.top();
            st.pop();
        }

        return res;
    }

    bool backspaceCompare(string s, string t) {
        int n = s.size();
        int m = t.size();

        if(m != n){
            return false;
        }

        string sc = compression(s);
        string tc = compression(t); 

        return sc == tc;

    }
};