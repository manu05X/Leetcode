class Solution {
    public int lengthOfLastWord(String s) {
        int n = s.length();
        int p = n-1;
        while(p >= 0 && s.charAt(p) == ' '){
            p--;
        }

        int length = 0;
        while(p >= 0 && s.charAt(p) != ' '){
            p--;
            length++;
        }
        return length;
    }
}