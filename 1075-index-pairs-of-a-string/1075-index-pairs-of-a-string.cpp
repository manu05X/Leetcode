// TrieNode represents each node in the Trie data structure
class TrieNode {
public:
    TrieNode* child[26]; // Each node can have 26 children for lowercase a-z
    bool isEnd; // Marks whether the current node is the end of a word

    // Constructor initializes all child pointers to nullptr and isEnd to false
    TrieNode() {
        for (int i = 0; i < 26; i++) {
            child[i] = nullptr;
        }
        isEnd = false;
    }

    // Checks if the current node has a child node for the given character
    bool containsKey(char ch) {
        return child[ch - 'a'] != nullptr;
    }

    // Creates a new child node for the given character
    void put(char ch, TrieNode* node) {
        child[ch - 'a'] = node;
    }

    // Returns the child node corresponding to the given character
    TrieNode* get(char ch) {
        return child[ch - 'a'];
    }

    // Marks this node as the end of a word
    void setEnd() {
        isEnd = true;
    }

    // Returns true if this node is the end of a word
    bool isEndOfWord() {
        return isEnd;
    }
};

// Trie is a tree-like data structure to store a dynamic set of strings
class Trie {
public:
    TrieNode* root;

    // Initialize the trie with an empty root node
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the Trie
    void insert(const string& word) {
        TrieNode* node = root;
        for (char ch : word) {
            // If the current character is not in the Trie, create a new node
            if (!node->containsKey(ch)) {
                node->put(ch, new TrieNode());
            }
            // Move to the corresponding child node
            node = node->get(ch);
        }
        // After inserting all characters, mark the end node
        node->setEnd();
    }
};

// Solution class to solve the problem using the Trie
class Solution {
public:
    // Returns all index pairs [i, j] such that text[i..j] is in words
    vector<vector<int>> indexPairs(string text, vector<string>& words) {
        Trie trie;

        // Insert all words into the Trie for fast prefix matching
        for (const string& word : words) {
            trie.insert(word);
        }

        vector<vector<int>> ans;

        // Iterate through each character in the input text
        for (int i = 0; i < text.size(); i++) {
            TrieNode* node = trie.root;

            // From index i, try to find words in the Trie
            for (int j = i; j < text.size(); j++) {
                char ch = text[j];

                // If the character is not in Trie, stop searching
                if (!node->containsKey(ch)) break;

                // Move to the child node
                node = node->get(ch);

                // If this node marks the end of a word, add the pair
                if (node->isEndOfWord()) {
                    ans.push_back({i, j});
                }
            }
        }

        return ans;
    }
};
