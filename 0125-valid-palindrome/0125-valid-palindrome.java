class Solution {
    public boolean isPalindrome(String s) {
        // Convert the string to lowercase and remove non-alphanumeric characters
        // This regular expression replaces any character that is not an alphabet (a-z, A-Z) or a number (0-9) with an empty string, effectively removing them from the original string
        s = s.replaceAll("[^a-zA-Z0-9]", "");
        s = s.toLowerCase();

        int left = 0;
        int right = s.length()-1;

        while(left < right){
            if(s.charAt(left) != s.charAt(right))
            {
                return false;
            }
            left++;
            right--;
        }

        return true;
    }
}

/*
Character.toLowerCase(A)
Character.isLetterOrDigit(j)

*/