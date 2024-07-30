class Solution {
public:
    int minimumDeletions(string s) {
        stack<char> st;
        int n = s.size(), bCount = 0;
        int deletCount = 0;

        for(int i = 0; i < n; i++){
            char x = s[i];

            if(x == 'b'){
                bCount++;
            } else {
                deletCount = min(deletCount+1, bCount);
            }
        }

        return deletCount;
    }
};