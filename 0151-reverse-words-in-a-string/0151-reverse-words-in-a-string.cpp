class Solution {
public:
// A function that reverses characters from startRev to endRev in place
void StrRev(string &str, int startRev, int endRev) {
    while (startRev < endRev) {
        char temp = str[startRev];
        str[startRev] = str[endRev];
        str[endRev] = temp;
        startRev++;
        endRev--;
    }
}
    string reverseWords(string s) 
    {
        s = regex_replace(s, regex("^ +| +$|( ) +"), "$1");

        int strLen = s.length() - 1;
    
        StrRev(s, 0, strLen);

        for (int start = 0, end = 0; end <= strLen; ++end) {
            if (end == strLen || s[end] == ' ') {
                int endIdx = (end == strLen) ? end : end - 1;
                StrRev(s, start, endIdx);
                start = end + 1;
            }
        }

        return s;
    }
};



/*
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
*/