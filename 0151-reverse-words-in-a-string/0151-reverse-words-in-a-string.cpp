class Solution {
public:

    string reverseWords(string s) 
    {
       if (s.empty()) return "";

        // Step 1: Reverse the whole string
        reverse(s, 0, s.length() - 1);
        // Step 2: Reverse each word
        reverseWord(s);
        // Step 3: Clean up spaces
        return cleanSpaces(s);
    }


    void reverse(string &s, int l, int r){
        while(l < r){
            swap(s[l], s[r]);
            l++;
            r--;
        }
    }

    void reverseWord(string &s){
        int n = s.length();
        int i = 0, j = 0;

        while (i < n) {
            while (i < j || i < n && s[i] == ' ') // Skip spaces
            {
                i++;
            }
            while (j < i || j < n && s[j] != ' ') // Skip non-spaces
            {
                j++;
            }
            reverse(s, i, j - 1);                      // Reverse the word
        } 
    }

     string cleanSpaces(string &s) {
        int n = s.length();
        int i = 0, j = 0;

        while (j < n) {
            while (j < n && s[j] == ' ') j++;             // Skip spaces
            while (j < n && s[j] != ' ') s[i++] = s[j++]; // Keep non-spaces
            while (j < n && s[j] == ' ') j++;             // Skip spaces
            if (j < n) s[i++] = ' ';                      // Keep only one space
        }

        return s.substr(0, i); // Return the cleaned-up string
    }
};


// class Solution {
// public:
// // A function that reverses characters from startRev to endRev in place
// void StrRev(string &str, int startRev, int endRev) {
//     while (startRev < endRev) {
//         char temp = str[startRev];
//         str[startRev] = str[endRev];
//         str[endRev] = temp;
//         startRev++;
//         endRev--;
//     }
// }
//     string reverseWords(string s) 
//     {
//         s = regex_replace(s, regex("^ +| +$|( ) +"), "$1");

//         int strLen = s.length() - 1;
    
//         StrRev(s, 0, strLen);

//         for (int start = 0, end = 0; end <= strLen; ++end) {
//             if (end == strLen || s[end] == ' ') {
//                 int endIdx = (end == strLen) ? end : end - 1;
//                 StrRev(s, start, endIdx);
//                 start = end + 1;
//             }
//         }

//         return s;
//     }
// };



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