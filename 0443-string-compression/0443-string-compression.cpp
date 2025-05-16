class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int write = 0;  // position to write compressed characters
        int i = 0;      // read pointer

        while (i < n) {
            char currentChar = chars[i];
            int count = 0;

            // Count occurrences of the current character
            while (i < n && chars[i] == currentChar) {
                i++;
                count++;
            }

            // Write the character
            chars[write++] = currentChar;

            // If count > 1, write its digits
            if (count > 1) {
                string countStr = to_string(count);
                for (char c : countStr) {
                    chars[write++] = c;
                }
            }
        }

        // Return the new length of the compressed array
        return write;
    }
};
