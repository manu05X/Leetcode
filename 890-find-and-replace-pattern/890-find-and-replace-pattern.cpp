class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;
        // Loop within words
        for (auto word : words) {
            if (isPattern(word, pattern))
                ans.push_back(word);
        }        
        return ans;
    }
    
    
    bool isPattern(string &word, string &pattern) {
        // notes all trasnlations: i.e. a -> m, b-> e
        unordered_map<char, char> note;
        // notes all chars from word thats been used
        unordered_map<char, int> usedChars;
        
        // Current char of word and pattern
        char w, p;
        
        // Loop through each char
        for (int i = 0; i < word.size(); ++i) {
            w = word[i];
            p = pattern[i];            
            // p has been noted as some w, and they are not the same
            // OR
            // p has never been noted, but w has been used as some other p before
            if (note[p] && note[p] != w || !note[p] && usedChars[w] == 1) 
                return false;
            else {
                note[p] = w;
                usedChars[w] = 1;
            }
        }
        
        return true;
    }
};