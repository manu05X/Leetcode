class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        // Convert wordDict to an unordered_set for faster lookups
        unordered_set<string> wordDictSet(wordDict.begin(), wordDict.end());
        
        // dp array where dp[i] is true if the substring s[0...i-1] can be segmented into words in wordDict
        vector<bool> dp(s.length() + 1, false);
        
        // Base case: an empty string can always be segmented (considered as true)
        dp[0] = true;

        // Iterate over all possible lengths of the substring (from 1 to s.length())
        for (int i = 1; i <= s.length(); i++) {
            // For each i, check all possible partitions by iterating over j
            for (int j = 0; j < i; j++) {
                // Extract substring s[j...i-1], i.e., from j to i
                string curr = s.substr(j, i - j);
                
                // If dp[j] is true (i.e., the substring s[0...j-1] can be segmented)
                // and the current substring s[j...i-1] exists in wordDictSet,
                // then set dp[i] to true and break the inner loop (no need to check further)
                if (dp[j] && wordDictSet.find(curr) != wordDictSet.end()) {
                    dp[i] = true;
                    break;
                }
            }
        }

        // Return whether the entire string s can be segmented, which is stored in dp[s.length()]
        return dp[s.length()];
    }
};




// struct TrieNode {
//     bool isWord;
//     unordered_map<char, TrieNode*> children;
//     TrieNode() : isWord(false), children(unordered_map<char, TrieNode*>()) {}
// };

// class Solution {
// public:
//     bool wordBreak(string s, vector<string>& wordDict) {
//         TrieNode* root = new TrieNode();
//         for (string word : wordDict) {
//             TrieNode* curr = root;
//             for (char c : word) {
//                 if (curr->children.find(c) == curr->children.end()) {
//                     curr->children[c] = new TrieNode();
//                 }
//                 curr = curr->children[c];
//             }

//             curr->isWord = true;
//         }

//         vector<bool> dp(s.length());
//         for (int i = 0; i < s.length(); i++) {
//             if (i == 0 || dp[i - 1]) {
//                 TrieNode* curr = root;
//                 for (int j = i; j < s.length(); j++) {
//                     char c = s[j];
//                     if (curr->children.find(c) == curr->children.end()) {
//                         // No words exist
//                         break;
//                     }

//                     curr = curr->children[c];
//                     if (curr->isWord) {
//                         dp[j] = true;
//                     }
//                 }
//             }
//         }

//         return dp[s.length() - 1];
//     }
// };
