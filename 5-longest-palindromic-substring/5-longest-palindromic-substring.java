class Solution 
{
    public String longestPalindrome(String s) 
    {
        if(s == null || s.length() < 1)
            return "";
        int l = 0, r = 0;
        for(int c = 0; c < s.length(); c++)
        {
            int l1 = expandAroundCenter(s, c, c);
            int l2 = expandAroundCenter(s, c, c+1);
            
            int len = Math.max(l1, l2);
            if (len > r - l) 
            {
                l = c - (len - 1) / 2;
                r = c + len / 2;
            }
        }
        return s.substring(l, r + 1);
    }
    private int expandAroundCenter(String s, int left, int right) 
    {
        int L = left, R = right;
        while (L >= 0 && R < s.length() && s.charAt(L) == s.charAt(R)) 
        {
            L--;
            R++;
        }
        return R - L - 1;
    }
}
