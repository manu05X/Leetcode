class TrieNode {
public:
    TrieNode* children[26];
    bool isEnd;

    TrieNode() {
        for(int i = 0; i < 26; ++i)
            children[i] = nullptr;
        isEnd = false;
    }

    bool contains(char ch) {
        return children[ch - 'a'] != nullptr;
    }

    void insert(char ch, TrieNode* node) {
        children[ch - 'a'] = node;
    }

    TrieNode* get(char ch) {
        return children[ch - 'a'];
    }

    void markEnd() {
        isEnd = true;
    }
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode();
    }

    // Insert a word into the Trie
    void insert(const string& word) {
        TrieNode* node = root;
        for(char ch : word) {
            if (!node->contains(ch)) {
                node->insert(ch, new TrieNode());
            }
            node = node->get(ch);
        }
        node->markEnd();
    }
};

class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        int n = s.length();
        Trie trie;

        // Insert all dictionary words into Trie
        for (const string& word : dictionary) {
            trie.insert(word);
        }

        // dp[i] = min extra chars from i to end
        vector<int> dp(n + 1, 0);

        // Process from end to start
        for (int i = n - 1; i >= 0; --i) {
            // Option 1: skip s[i], count as extra
            dp[i] = 1 + dp[i + 1];  

            TrieNode* node = trie.root;
            for (int j = i; j < n; ++j) {
                if (!node->contains(s[j])) break;
                node = node->get(s[j]);

                // Option 2: s[i..j] is a word, so 0 extra chars
                if (node->isEnd) {
                    dp[i] = min(dp[i], dp[j + 1]);
                }
            }
        }

        return dp[0];  // Minimum extra chars from index 0 to end
    }
};
