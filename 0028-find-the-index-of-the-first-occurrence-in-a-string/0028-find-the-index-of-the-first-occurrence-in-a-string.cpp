class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size();
        int m = needle.size();
        
        if(m == 0)
            return 0;
        
        int j = 0 ; 
        for(int i = 0; i < n; i++)
        {
            //chart at i & j are equal
            if(haystack[i] == needle[j])
            {
                //increasing j for next match
                j++;
            }
            else
            {
                //if char does not match then we move out i in haystack to starting of match began
                i -=j;
                j=0; // j to starting of needle
            }
            if(j==m)
            {
				return i - j +1 ;
			}
        }
        return -1;
    }
};