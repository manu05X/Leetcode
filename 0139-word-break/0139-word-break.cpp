// class Solution {
// public:
//     bool wordBreak(string s, vector<string>& wordDict) {
//         unordered_set<string> wordDictSet(wordDict.begin(), wordDict.end());
//         vector<bool> dp(s.length() + 1, false);
//         dp[0] = true;

//         for (int i = 1; i <= s.length(); i++) {
//             for (int j = 0; j < i; j++) {
//                 //s.substr(startIndex, LengthFromStartIndx);
//                 string curr = s.substr(j, i - j);
//                 if (dp[j] && wordDictSet.find(curr) != wordDictSet.end()) {
//                     dp[i] = true;
//                     break;
//                 }
//             }
//         }

//         return dp[s.length()];
//     }
// };

struct TrieNode {
    bool isWord;
    unordered_map<char, TrieNode*> children;
    TrieNode() : isWord(false), children(unordered_map<char, TrieNode*>()) {}
};

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        TrieNode* root = new TrieNode();
        for (string word : wordDict) {
            TrieNode* curr = root;
            for (char c : word) {
                if (curr->children.find(c) == curr->children.end()) {
                    curr->children[c] = new TrieNode();
                }
                curr = curr->children[c];
            }

            curr->isWord = true;
        }

        vector<bool> dp(s.length());
        for (int i = 0; i < s.length(); i++) {
            if (i == 0 || dp[i - 1]) {
                TrieNode* curr = root;
                for (int j = i; j < s.length(); j++) {
                    char c = s[j];
                    if (curr->children.find(c) == curr->children.end()) {
                        // No words exist
                        break;
                    }

                    curr = curr->children[c];
                    if (curr->isWord) {
                        dp[j] = true;
                    }
                }
            }
        }

        return dp[s.length() - 1];
    }
};
