class Solution {
public:
    string reverseWords(string s) {
        // Use a stringstream to extract words
        stringstream ss(s);
        vector<string> words;

        // Extract words and store them in a vector
        string word;
        while (ss >> word) {
            words.push_back(word);
        }

        // Reverse the order of words in the vector
        reverse(words.begin(), words.end());

        // Build the result string by concatenating the reversed words
        string result;
        for (const string& w : words) {
            result += result.empty() ? w : " " + w;
        }

        return result;
    }
};