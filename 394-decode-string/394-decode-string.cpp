class Solution {
public:
    string decodeString(string s) {
        int idx = 0;
        return decodeString(s,idx);
    }
    
    string decodeString(const string& s, int& idx)
    {
        string res;
        while(idx < s.length() && s[idx] != ']')
        {
            if(!isdigit(s[idx]))
                res += s[idx++];
            else
            {
                int k = 0;
                while(idx < s.length() && isdigit(s[idx]))
                    k = k*10 + s[idx++]-'0';
                
                idx++;
                string decod = decodeString(s,idx);
                
                idx++;
                while(k-- > 0)
                    res += decod;
            }
        }
        return res;
    }
};