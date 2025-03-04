class Solution {
    // Helper function to find the length of the longest palindrome centered at 'leftCenter' and 'rightCenter'
    public int expandAroundCenter(String inputString, int leftCenter, int rightCenter) {
        // Expand outwards as long as the characters match and within bounds
        while (leftCenter >= 0 && rightCenter < inputString.length() && 
               inputString.charAt(leftCenter) == inputString.charAt(rightCenter)) {
            leftCenter--;  // Move left pointer leftward
            rightCenter++; // Move right pointer rightward
        }

        // Return the length of the found palindrome
        return rightCenter - leftCenter - 1;
    }

    public String longestPalindrome(String inputString) {
        int stringLength = inputString.length(); // Get the length of the input string

        if (stringLength == 0) {
            return ""; // Edge case: if the string is empty, return an empty string
        }

        int longestPalindromeStart = 0; // Stores the starting index of the longest palindrome
        int longestPalindromeEnd = 0;   // Stores the ending index of the longest palindrome

        // Iterate through each character in the string
        for (int currentIndex = 0; currentIndex < stringLength; currentIndex++) {
            // Check for odd-length palindrome (single character center)
            int oddLengthPalindrome = expandAroundCenter(inputString, currentIndex, currentIndex);

            // Check for even-length palindrome (double character center)
            int evenLengthPalindrome = expandAroundCenter(inputString, currentIndex, currentIndex + 1);

            // Get the maximum length palindrome from both cases
            int maxPalindromeLength = Math.max(oddLengthPalindrome, evenLengthPalindrome);

            // If the current palindrome is longer than the previous longest
            if (maxPalindromeLength > longestPalindromeEnd - longestPalindromeStart) {
                // Update start and end indices based on the center position
                longestPalindromeStart = currentIndex - (maxPalindromeLength - 1) / 2;
                longestPalindromeEnd = currentIndex + maxPalindromeLength / 2;
            }
        }

        // Extract and return the longest palindrome substring
        return inputString.substring(longestPalindromeStart, longestPalindromeEnd + 1);
    }
}


/*
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

            int maxLen = Math.max(l1, l2); // Get the maximum length palindrome from both cases

            // If the current palindrome is longer than the previous longest
            if (maxLen > end - start) {
                start = i - (maxLen - 1) / 2; // Update start index based on the center position
                end = i + maxLen / 2;         // Update end index based on the center position
            }
        }

        return s.substring(start, end + 1); // Extract the longest palindrome substring
    }
}

*/