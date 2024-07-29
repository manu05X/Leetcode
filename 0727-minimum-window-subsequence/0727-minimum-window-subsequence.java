class Solution {
    public String minWindow(String s1, String s2) {
        int n1 = s1.length();
        int n2 = s2.length();

        int p1 = 0, p2 = 0;

        int minLength = Integer.MAX_VALUE;
        String ans = "";

        while(p1 < n1){
            if(s1.charAt(p1) == s2.charAt(p2)){
                p2++;

                if(p2 == n2){
                    p2--;

                    int start = p1, end = p1+1;
                    
                    while(p2 >= 0){
                        if(s1.charAt(start) == s2.charAt(p2)){
                            p2--;
                        }
                        start--;
                    }
                    start +=1;

                    if(minLength > end-start){
                        minLength = end-start;
                        ans = s1.substring(start, end);
                    }
                    p1 = start+1;
                    p2 = 0;
                }
            }
            p1++;
        }

        return ans;
        
    }
}