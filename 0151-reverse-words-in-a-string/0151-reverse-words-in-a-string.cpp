class Solution {
public:
    string reverseWords(string s) {
        int h = s.size()-1;
        int i = 0;
        string ans = "";
        
        while(h >= 0)
        {
            while(h >= 0 && s[h] == ' ')
                h--;

            i = h;
            string temp = "";

            while(i >= 0 && s[i] != ' ')
            {
                temp += s[i];
                i--;
            }

            reverse(temp.begin(), temp.end()); 

        
            if(temp.size()) 
                ans += ans.size() == 0 ?  temp : " " + temp;

            h = i;
        }
        ans = ans.substr(0, ans.size());
        return ans;
    }
};