class Solution {
    // Helper function to check the longest palindrome centered at 'left' and 'right'
    public int isPalindrome(String s, int left, int right) {
        // Expand outwards as long as the characters match and within bounds
        while (left >= 0 && right < s.length() && s.charAt(left) == s.charAt(right)) {
            left--;  // Move left pointer leftward
            right++; // Move right pointer rightward
        }

        return right - left - 1; // Return the length of the found palindrome
    }

    public String longestPalindrome(String s) {
        int n = s.length(); // Get the length of the string

        if (n == 0) {
            return ""; // Edge case: if the string is empty, return an empty string
        }

        int start = 0; // Stores the starting index of the longest palindrome
        int end = 0;   // Stores the ending index of the longest palindrome

        // Iterate through each character in the string
        for (int i = 0; i < n; i++) {
            int l1 = isPalindrome(s, i, i);      // Check for odd-length palindrome (single character center)
            int l2 = isPalindrome(s, i, i + 1);  // Check for even-length palindrome (double character center)

            int len = Math.max(l1, l2); // Get the maximum length palindrome from both cases

            // If the current palindrome is longer than the previous longest
            if (len > end - start) {
                start = i - (len - 1) / 2; // Update start index based on the center position
                end = i + len / 2;         // Update end index based on the center position
            }
        }

        return s.substring(start, end + 1); // Extract the longest palindrome substring
    }
}
