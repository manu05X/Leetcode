class Solution {
    public String longestPrefix(String s) {
        int n = s.length(); // Get the length of the string

        int left = 0, right = 1; // Initialize pointers for LPS computation
        int[] lps = new int[n]; // LPS (Longest Prefix Suffix) array to store prefix lengths

        while (right < n) { // Traverse the string from index 1 to n-1
            if (s.charAt(right) == s.charAt(left)) { // If characters at left and right match
                lps[right] = left + 1; // Store the length of the matching prefix
                right++; // Move the right pointer forward
                left++; // Move the left pointer forward
            } else { // If characters don't match
                if (left == 0) { // If left pointer is at the start, no prefix can be formed
                    lps[right] = 0; // Set LPS value to 0
                    right++; // Move to the next character
                } else {
                    left = lps[left - 1]; // Move left pointer back to previous LPS position
                }
            }
        }

        return s.substring(0, lps[n - 1]); // Return the longest prefix which is also a suffix

    }
}

/*
level



ababab

*/