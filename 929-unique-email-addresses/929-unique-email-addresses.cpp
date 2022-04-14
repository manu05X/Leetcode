class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> st;
        for(string &i : emails)
        {
            string cleanEmail;
            for(char c : i)
            {
                if(c == '+' || c == '@')
                    break;
                if(c == '.')
                    continue;
                cleanEmail += c;
            }
            cleanEmail += i.substr(i.find('@'));
            st.insert(cleanEmail);
        }
        
        return st.size();
    }
};