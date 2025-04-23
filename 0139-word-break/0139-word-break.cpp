/*
1> Put all words in a set of wordDictionary
2> take a bool array of length s and make it as false;
3> Extract substring of all possible length and combination.
4> If substring is present in set then make it as true; 


*/

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


/*

// Define the structure of a Trie Node
struct TrieNode {
    bool isWord; // Indicates whether the node represents the end of a valid word
    unordered_map<char, TrieNode*> children; // Stores children nodes for each character

    // Constructor initializes isWord to false and an empty children map
    //TrieNode() : isWord(false), children(unordered_map<char, TrieNode*>()) {}

    TrieNode() {
        isWord = false;
        children = unordered_map<char, TrieNode*>();
    }
};

class Solution {
public:
    // Main function to determine if a string `s` can be segmented into words from `wordDict`
    bool wordBreak(string s, vector<string>& wordDict) {
        // Step 1: Build a Trie from the word dictionary
        TrieNode* root = new TrieNode();
        for (string word : wordDict) {
            TrieNode* curr = root;
            for (char c : word) {
                // If character `c` is not a child of the current node, create a new TrieNode
                if (curr->children.find(c) == curr->children.end()) {
                    curr->children[c] = new TrieNode();
                }
                curr = curr->children[c]; // Move to the next node
            }
            curr->isWord = true; // Mark the end of the word
        }

        // Step 2: Use dynamic programming to check if the string `s` can be segmented
        vector<bool> dp(s.length()); // dp[i] = true means s[0..i] can be segmented

        for (int i = 0; i < s.length(); i++) {
            // Start checking from index `i` only if it's the beginning or dp[i-1] is true
            if (i == 0 || dp[i - 1]) {
                TrieNode* curr = root;

                // Try to match substrings starting from `i` using the Trie
                for (int j = i; j < s.length(); j++) {
                    char c = s[j];

                    // If no matching child for `c`, no word in dict starts with s[i..j]
                    if (curr->children.find(c) == curr->children.end()) {
                        break;
                    }

                    curr = curr->children[c]; // Move to next node

                    // If we reached the end of a word in the Trie, mark dp[j] as true
                    if (curr->isWord) {
                        dp[j] = true;
                    }
                }
            }
        }

        // Return true if entire string can be segmented
        return dp[s.length() - 1];
    }
};


*/