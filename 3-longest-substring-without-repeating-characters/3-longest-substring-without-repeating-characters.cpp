//Approach 1: Brute Force
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();

        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (checkRepetition(s, i, j)) {
                    res = max(res, j - i + 1);
                }
            }
        }

        return res;
    }

    bool checkRepetition(string& s, int start, int end) {
        vector<int> chars(128);

        for (int i = start; i <= end; i++) {
            char c = s[i];
            chars[c]++;
            if (chars[c] > 1) {
                return false;
            }
        }

        return true;
    }
};
//Time complexity : O(n3)
----------------------------------------------------------------------------------------------------------------------------------------------------
//Approach 2: Sliding Window
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> chars(128);

        int left = 0;
        int right = 0;

        int res = 0;
        while (right < s.length()) {
            char r = s[right];
            chars[r]++;

            while (chars[r] > 1) {
                char l = s[left];
                chars[l]--;
                left++;
            }

            res = max(res, right - left + 1);

            right++;
        }

        return res;
    }
};
//Time complexity : O(2n) -> O(n)
----------------------------------------------------------------------------------------------------------------------------------------------------
//Approach 3: Sliding Window Optimized
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
//Time complexity : O(n)
/*
Java (Assuming ASCII 128)

The previous implements all have no assumption on the charset of the string s.

If we know that the charset is rather small, we can replace the Map with an integer array as direct access table.

Commonly used tables are:

int[26] for Letters 'a' - 'z' or 'A' - 'Z'
int[128] for ASCII
int[256] for Extended ASCII
*/
----------------------------------------------------------------------------------------------------------------------------------------------------
//
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // we will store a senitel value of -1 to simulate 'null'/'None' in C++
        vector<int> chars(128, -1);

        int left = 0;
        int right = 0;

        int res = 0;
        while (right < s.length()) {
            char r = s[right];

            int index = chars[r];
            if (index != -1 and index >= left and index < right) {
                left = index + 1;
            }
            res = max(res, right - left + 1);

            chars[r] = right;
            right++;
        }
        return res;
    }
};
//Time complexity : O(n)
