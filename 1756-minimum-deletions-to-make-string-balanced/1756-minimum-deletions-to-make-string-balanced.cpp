class Solution {
public:
    int minimumDeletions(string s) {
        stack<char> st;
        int n = s.size(), bCount = 0;
        int deletCount = 0;

        //aababbab
        for(int i = 0; i < n; i++){
            char x = s[i]; //a,a,b,a,b,b,a,b

            if(x == 'b'){
                bCount++; //1,2,3,4
            } else {
                deletCount = min(deletCount+1, bCount); //0,0,1,2,
            }
        }

        return deletCount;
    }
};