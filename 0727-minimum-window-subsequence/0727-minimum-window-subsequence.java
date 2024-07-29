class Solution {
    public String minWindow(String s1, String s2) {
        int n1 = s1.length();
        int n2 = s2.length();

        int p1 = 0, p2 = 0;

        int minLength = Integer.MAX_VALUE;
        String ans = "";

        // iterate over str1 while we haven't reached the end of pointer one.
        while(p1 < n1)
        {
            if(s1.charAt(p1) == s2.charAt(p2))
            {
                // increment to find the next matching element.
                p2++;
                // check if a valid substring has been found
                if(p2 == n2){
                    p2--;
                    // here we will stretch the window from start to end by decrementing the size of start;
                    int start = p1, end = p1+1;
                    // we'll iterate backwards to find all the chars of s2
                    // abced ace
                    while(p2 >= 0){
                        if(s1.charAt(start) == s2.charAt(p2)){
                            p2--;
                        }
                        start--;
                    }
                    start +=1;

                    // update minSubLen and minSubsequence if current subsequence is shorter
                    if(minLength > end-start)
                    {
                        minLength = end-start;
                        ans = s1.substring(start, end);
                    }
                    // reassigning the p1 and p2
                    p1 = start+1;
                    p2 = 0;
                }
            }
            p1++;
        }
        return ans;
    }
}