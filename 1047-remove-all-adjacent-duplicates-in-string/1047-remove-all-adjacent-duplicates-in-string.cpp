class Solution {
public:
    string removeDuplicates(string s) {
        int write = 0;
        int n = s.size();
        
        for(int read = 0; read < n; ++read, write++)
        {
            s[write] = s[read];
            
            if(write > 0 && s[write - 1] == s[write])
                write -= 2;
        }
        return s.substr(0,write);
    }
};