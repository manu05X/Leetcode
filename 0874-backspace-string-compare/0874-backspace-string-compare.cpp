class Solution {
public:
    string processString(string str) 
    {
        string processed;
        for (char c : str) 
        {
            if (!processed.empty() && c == '#') 
            {
                processed.pop_back();
            } 
            else if (c != '#') 
            {
                processed.push_back(c);
            }
        }
        return processed;
    }
    bool backspaceCompare(string s, string t) 
    {
        return processString(s) == processString(t);
    }
};

/*
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


*/