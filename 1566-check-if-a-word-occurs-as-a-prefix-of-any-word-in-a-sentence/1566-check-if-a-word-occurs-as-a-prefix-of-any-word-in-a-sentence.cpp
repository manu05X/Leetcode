class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int idx = 1; // 1-based index of words
        int n = sentence.size();
        int m = searchWord.size();

        int start = 0; // Start index of the current word
        for (int i = 0; i <= n; i++) {
            if (i == n || sentence[i] == ' ') {
                // Check if the word matches the prefix
                if (i - start >= m && sentence.substr(start, m) == searchWord) {
                    return idx;
                }
                idx++;
                start = i + 1; // Move to the next word
            }
        }

        return -1; // Not found
    }
};
