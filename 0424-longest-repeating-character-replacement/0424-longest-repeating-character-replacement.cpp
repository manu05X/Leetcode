class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length();
        vector<int> freq(26, 0); // Frequency map for characters A-Z
        int left = 0; // Left pointer of the window
        int maxLen = 0; // Maximum length of the valid window
        int maxFreq = 0; // Maximum frequency of any character in the current window

        // Iterate over the string with the right pointer
        for (int right = 0; right < n; right++) {
            // Update the frequency of the current character
            freq[s[right] - 'A']++;
            // Update the maximum frequency in the current window
            maxFreq = max(maxFreq, freq[s[right] - 'A']);

            // If the number of characters to replace exceeds k, shrink the window
            if ((right - left + 1) - maxFreq > k) {
                freq[s[left] - 'A']--; // Decrement the frequency of the left character
                left++; // Move the left pointer
            }

            // Update the maximum window size
            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};

/*
class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> charCount(26, 0); // Counter for each letter's frequency within the sliding window
        int left = 0; // Left index of the sliding window
        //int right = 0; // Right index of the sliding window
        int longestSubstringLength = 0;
        int maxCharCount = 0; // Variable to keep track of the count of the most frequent character within the window
      
        // Iterate over the characters of the string
        for (int right = 0; right < s.size(); ++right) {
            charCount[s[right] - 'A']++; // Increment the count for the current character
          
            // Update the max frequency character count seen so far in the current window, not nessasary in the current window
            maxCharCount = max(maxCharCount, charCount[s[right] - 'A']);
            int currWindowSize = right - left + 1;
          
            // Check if the current window size minus the count of the max frequency character
            // is greater than k, if so, shrink the window from the left
            if (currWindowSize - maxCharCount > k) {
                charCount[s[left] - 'A']--; // Decrement the count for the character at the left index as it's going out of the window
                left++; // Shrink the window from the left
                //update the window size
                currWindowSize = right - left + 1;
            }
            // the window is valid at this point, note down the length
            // size of the window never decreases
            longestSubstringLength = right - left + 1;
        }
      
        // The length of the largest window compliant with the condition serves as the answer
        return longestSubstringLength;
    }
};

*/

/*
we can say that by currWindowSize - maxCharCount we get the count of number of less frequent character. Count of less frequent character must be less than or equal to k.

- currWindowSize - maxCharCount gives you the count of less frequent characters (or characters that are not the most frequent one) in the current window.
- For the current window to be valid (meaning it can be transformed into a window where all characters are the same), the count of these less frequent characters must be less than or equal to k, which is the maximum number of character replacements allowed.


s = "ABAB", k = 2
r = 0, l = 0 


Let's go through an example:
Consider the string s = "AABABBA" and k = 1.

1> Initial window (right = 0):

    Window: "A", currWindowSize = 1, maxCharCount = 1 (for A)
    currWindowSize - maxCharCount = 1 - 1 = 0, which is <= k. This is valid, so longestSubstringLength = 1.

2> Second window (right = 1):

    Window: "AA", currWindowSize = 2, maxCharCount = 2 (for A)
    currWindowSize - maxCharCount = 2 - 2 = 0, which is <= k. This is valid, so longestSubstringLength = 2.

3> Third window (right = 2):

Window: "AAB", currWindowSize = 3, maxCharCount = 2 (for A)
currWindowSize - maxCharCount = 3 - 2 = 1, which is <= k. This is valid, so longestSubstringLength = 3.

4> Fourth window (right = 3):

Window: "AABA", currWindowSize = 4, maxCharCount = 3 (for A)
currWindowSize - maxCharCount = 4 - 3 = 1, which is <= k. This is valid, so longestSubstringLength = 4.

5> Fifth window (right = 4):

    Window: "AABAB", currWindowSize = 5, maxCharCount = 3 (for A)
    currWindowSize - maxCharCount = 5 - 3 = 2, which is greater than k. This window is invalid, so we shrink it by moving left to 1.

After shrinking, the window becomes "ABAB", and the process continues until the valid window size is maximized.


*/