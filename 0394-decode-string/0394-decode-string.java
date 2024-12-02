class Solution {
    int idx = 0;
    public String decodeString(String s) {
        StringBuilder ans = new StringBuilder();
        int n = s.length();

        while(idx < n && s.charAt(idx) != ']'){
            if(!Character.isDigit(s.charAt(idx))){
                ans.append(s.charAt(idx));
                idx++;
            } 
            else 
            {
                int k = 0;

                // build k while next character is a digit
                while(idx < n && Character.isDigit(s.charAt(idx))){
                    k = k*10 + s.charAt(idx) - '0';
                    idx++;
                }

                // ignore the opening bracket '['
                idx++;
                String decoded = decodeString(s);

                // ignore the opening bracket ']'
                idx++;

                // build k[decodedString] and append to the result
                while(k-- > 0){
                    ans.append(decoded);
                }
            }
        }

        return new String(ans);
    }
}