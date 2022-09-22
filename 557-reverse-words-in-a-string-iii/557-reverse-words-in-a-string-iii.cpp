class Solution {
public:
    string reverseWords(string s) 
    {
        int lastSpaceIdx = -1;
        int len = s.size();
        
        for(int i = 0; i <= len; i++)
        {
            if(i == len || s[i] == ' ')
            {
                int stIdx = lastSpaceIdx + 1;
                int endIdx = i - 1;
                
                while(stIdx < endIdx)
                {
                    char tmp = s[stIdx];
                    s[stIdx] = s[endIdx];
                    s[endIdx] = tmp;
                    stIdx++;
                    endIdx--;
                }
                lastSpaceIdx = i;
            }
            
        }
        return s;
    }
};