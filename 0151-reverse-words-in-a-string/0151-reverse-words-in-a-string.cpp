class Solution {
public:
    string reverseWords(string s) {
        // Step 1: Reverse the whole string to bring words in reverse order
        reverse(s.begin(), s.end());

        int n = s.size();
        int left = 0;     // Start index of the current word
        int right = 0;    // End index where the next word will be written
        int i = 0;        // Pointer to traverse the original string

        while (i < n) {
            // Skip spaces
            while (i < n && s[i] == ' ') i++;

            // If we reach the end after skipping spaces, break
            if (i == n) break;

            // Start writing the word from 'right' index
            // Copy the word (non-space characters) to the 'right' position
            while (i < n && s[i] != ' ') {
                s[right++] = s[i++];
            }

            // Reverse the current word to restore correct order (since the whole string was reversed earlier)
            reverse(s.begin() + left, s.begin() + right);

            // Add a single space after the word
            s[right++] = ' ';

            // Set 'left' to the current 'right' for the next word
            left = right;

            // Move past the space
            i++;
        }

        // Remove the trailing space by resizing the string
        // If there were words, we remove the extra space added after the last word
        s.resize(right > 0 ? right - 1 : 0);

        return s;
    }
};


/*
class Solution {
public:
    string reverseWords(string s) {
        // Step 1: Remove leading, trailing, and extra spaces
        int n = s.size();
        string temp;
        int i = 0;

        // Skip leading spaces
        while(i < n && s[i] == ' ') i++;

        while(i < n) {
            if(s[i] != ' ') {
                temp += s[i];
            } else {
                // Add one space and skip all additional spaces
                temp += ' ';
                while(i < n && s[i] == ' ') i++;
                continue;
            }
            i++;
        }

        // Remove trailing space if any
        if(!temp.empty() && temp.back() == ' ')
            temp.pop_back();

        s = temp;
        n = s.size();

        // Step 2: Reverse each word
        int p1 = 0;
        for(int i = 0; i <= n; i++) {
            if(i == n || s[i] == ' ') {
                int p2 = i - 1;
                while(p1 < p2) swap(s[p1++], s[p2--]);
                p1 = i + 1;
            }
        }

        // Step 3: Reverse the whole string
        reverse(s.begin(), s.end());

        return s;
    }
};

*/