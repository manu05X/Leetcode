class Solution {
    public String removeDuplicates(String s) {
        StringBuilder ans = new StringBuilder();

        for(char x : s.toCharArray()){
            int n = ans.length();

            if(n > 0 && ans.charAt(n-1) == x){
                ans.deleteCharAt(n-1);
            } else {
                ans.append(x);
            }
        }

        return ans.toString();
    }
}