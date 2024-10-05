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

/*
s = "ABAB", k = 2
r = 0, l = 0 



*/