class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int windowStart = 0, maxLen = 0;
        unordered_map<char, int> charFreq;

        // in the following loop we try to extend the range [windowStart, windowEnd]
        for(int end = 0; end < s.size(); end++)
        {
            char rightChar = s[end];
            // shrink sliding window, until we are left with 'k' distinct characters in frequency map

            if(charFreq.find(rightChar) != charFreq.end())
            {
                windowStart = max(windowStart, charFreq[s[end]]);
            }
            
            maxLen = max(maxLen, end - windowStart + 1);
            charFreq[rightChar] = end+1;
        }
        return maxLen;
    }
};