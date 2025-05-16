class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(),s.end());
        int n=s.size();
        int left=0;
        int right=0;
        int i=0;
        while(i<n){
            while(i<n && s[i]==' ')i++;
            if(i==n)break; // to stop index going out of bounds
            while(i<n && s[i]!=' '){
                s[right++]=s[i++];
            }
            reverse(s.begin()+left,s.begin()+right);
            s[right++]=' ';
            left=right;
            i++;
        }
        s.resize(right-1);
        return s;
    }
};

/*
class Solution {
public:
    string reverseWords(string s) {
        // Step 1: Remove leading, trailing, and extra spaces
        int n = s.size();
        string temp;
        int i = 0;

        // Skip leading spaces
        while(i < n && s[i] == ' ') i++;

        while(i < n) {
            if(s[i] != ' ') {
                temp += s[i];
            } else {
                // Add one space and skip all additional spaces
                temp += ' ';
                while(i < n && s[i] == ' ') i++;
                continue;
            }
            i++;
        }

        // Remove trailing space if any
        if(!temp.empty() && temp.back() == ' ')
            temp.pop_back();

        s = temp;
        n = s.size();

        // Step 2: Reverse each word
        int p1 = 0;
        for(int i = 0; i <= n; i++) {
            if(i == n || s[i] == ' ') {
                int p2 = i - 1;
                while(p1 < p2) swap(s[p1++], s[p2--]);
                p1 = i + 1;
            }
        }

        // Step 3: Reverse the whole string
        reverse(s.begin(), s.end());

        return s;
    }
};

*/