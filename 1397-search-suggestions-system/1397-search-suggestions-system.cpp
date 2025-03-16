class Solution {
public:
    struct TrieNode {
        unordered_map<char, TrieNode*> children;
        vector<string> suggestions;
    };
    
    class Trie {
        TrieNode* root;
        
    public:
        Trie() {
            root = new TrieNode();
        }
        
        void insert(const string& product) {
            TrieNode* node = root;
            for (char c : product) {
                if (node->children.find(c) == node->children.end()) {
                    node->children[c] = new TrieNode();
                }
                node = node->children[c];
                if (node->suggestions.size() < 3) {  // Store up to 3 lexicographically smallest words
                    node->suggestions.push_back(product);
                }
            }
        }
        
        vector<vector<string>> search(const string& searchWord) {
            vector<vector<string>> result;
            TrieNode* node = root;
            for (char c : searchWord) {
                if (node->children.find(c) == node->children.end()) {
                    break;
                }
                node = node->children[c];
                result.push_back(node->suggestions);
            }
            while (result.size() < searchWord.size()) {
                result.push_back({}); // Add empty lists for remaining characters
            }
            return result;
        }
    };
    
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(), products.end()); // Sort lexicographically
        Trie trie;
        for (const string& product : products) {
            trie.insert(product);
        }
        return trie.search(searchWord);
    }
};
