class TrieNode{
public:
    unordered_map<char, TrieNode*> children;
    bool isEndOfWord = false;
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
        node->isEndOfWord = true;
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
            if (node->isEndOfWord) {
                return prefix;  // Found the shortest prefix
            }
        }
        return word;
    }

    string longestCommonPrefix() {
        TrieNode* node = root;
        string prefix;

        while (node && !node->isEndOfWord && node->children.size() == 1) {
            auto it = node->children.begin(); // Get the only child
            prefix += it->first;
            node = it->second;
        }

        return prefix;
    }
};


class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";  // Edge case: empty input

        Trie trie;
        for (const string& word : strs) {
            trie.insert(word);
        }

        return trie.longestCommonPrefix();
        
    }
};


/*


class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
    //    int s = strs[0].size();
    //    int n = strs.size();
       
    //    for(int i = 1; i < n; i++){
    //        int j = 0;
    //        while(j < strs[i].size() && strs[i][j] == strs[0][j]){
    //            j++;
    //        }
    //        s = min(s,j);
    //    }
    //    return strs[0].substr(0,s);
    if (strs.empty()) 
            return "";
        
        string prefix = strs[0];
        for (int i = 1; i < strs.size(); i++) 
        {
            while (strs[i].find(prefix) != 0) 
            {
                prefix = prefix.substr(0, prefix.length() - 1);
                if (prefix.empty()) 
                    return "";
            }
        }
        return prefix;
    }
};
*/