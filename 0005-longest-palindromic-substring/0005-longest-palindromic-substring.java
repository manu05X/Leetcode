class Solution {
    public int isPalindrome(String s, int left, int right) {
        while (left >= 0 && right < s.length() && s.charAt(left) == s.charAt(right)) {
            left--;
            right++;
        }

        return right - left - 1; // Corrected to return length of palindrome
    }

    public String longestPalindrome(String s) {
        int n = s.length();

        if (n == 0) {
            return "";
        }

        int start = 0;
        int end = 0;

        for (int i = 0; i < n; i++) 
        {
            int l1 = isPalindrome(s, i, i);      // Odd length palindrome
            int l2 = isPalindrome(s, i, i + 1);  // Even length palindrome

            int len = Math.max(l1, l2);

            if (len > end - start) {
                start = i - (len - 1) / 2; // Calculate start index
                end = i + len / 2;         // Calculate end index
            }
        }

        return s.substring(start, end + 1); // Corrected substring extraction
    }
}