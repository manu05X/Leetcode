class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    bool endOfWord = false;
};

class Trie {
    TrieNode* root;
public:
    Trie() {
        root = new TrieNode();
    }

    void insert(const string& word) {
        TrieNode* node = root;
        for (char c : word) {
            if (node->children.find(c) == node->children.end()) {
                node->children[c] = new TrieNode();
            }
            node = node->children[c];
        }
        node->endOfWord = true;
    }

    string getShortestPrefix(const string& word) {
        TrieNode* node = root;
        string prefix;
        for (char c : word) {
            if (node->children.find(c) == node->children.end()) {
                return word;  // No matching prefix found, return original word
            }
            prefix += c;
            node = node->children[c];
            if (node->endOfWord) {
                return prefix;  // Found the shortest prefix
            }
        }
        return word;
    }
};

class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        Trie trie;
        for (const string& word : dictionary) {
            trie.insert(word);
        }

        istringstream iss(sentence);
        string word, result;
        while (iss >> word) {
            if (!result.empty()) result += " ";
            result += trie.getShortestPrefix(word);
        }
        return result;
    }
};