class TrieNode {
public:
    TrieNode* children[26];
    bool isEnd;

    TrieNode() {
        for (int i = 0; i < 26; i++) children[i] = nullptr;
        isEnd = false;
    }

    bool contains(char ch) {
        return children[ch - 'a'] != nullptr;
    }

    void put(char ch, TrieNode* node) {
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

    void insert(const string& word) {
        TrieNode* node = root;
        for (char ch : word) {
            if (!node->contains(ch)) {
                node->put(ch, new TrieNode());
            }
            node = node->get(ch);
        }
        node->markEnd();
    }
};

class Solution {
public:
    Trie trie;
    unordered_map<int, vector<string>> memo;

    // DFS function to return all sentences from index 'start'
    vector<string> dfs(const string& s, int start) {
        // If already computed, return memoized result
        if (memo.count(start)) return memo[start];

        vector<string> res;
        TrieNode* node = trie.root;

        for (int end = start; end < s.size(); ++end) {
            char ch = s[end];
            if (!node->contains(ch)) break;
            node = node->get(ch);

            if (node->isEnd) {
                string word = s.substr(start, end - start + 1);
                if (end == s.size() - 1) {
                    // Reached end of string; add word as complete sentence
                    res.push_back(word);
                } else {
                    // Recurse for the rest of the string
                    vector<string> next = dfs(s, end + 1);
                    for (const string& suffix : next) {
                        res.push_back(word + " " + suffix);
                    }
                }
            }
        }

        return memo[start] = res;
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        // Build the Trie
        for (const string& word : wordDict) {
            trie.insert(word);
        }

        // Start DFS from index 0
        return dfs(s, 0);
    }
};



/*
class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end()); // Fast lookup
        unordered_map<int, vector<string>> memo; // Memoization

        return dfs(0, s, dict, memo);
    }

private:
    vector<string> dfs(int start, const string& s, unordered_set<string>& dict, unordered_map<int, vector<string>>& memo) {
        if (memo.count(start)) {
            return memo[start]; // Return cached results
        }

        vector<string> result;

        // Base case: if we reach the end of string, return a list with an empty string
        if (start == s.size()) {
            result.push_back("");
            return result;
        }

        // Try every possible end index to form a substring
        for (int end = start + 1; end <= s.size(); ++end) {
            string word = s.substr(start, end - start);
            if (dict.count(word)) {
                vector<string> subList = dfs(end, s, dict, memo); // Recursively solve for the rest
                for (const string& sub : subList) {
                    // If sub is empty, just add word. Else, append word + " " + sub
                    result.push_back(word + (sub.empty() ? "" : " " + sub));
                }
            }
        }

        return memo[start] = result; // Cache the result
    }
};


class TrieNode {
public:
    TrieNode* children[26];
    bool isEnd;

    TrieNode() {
        for (int i = 0; i < 26; i++) children[i] = nullptr;
        isEnd = false;
    }

    bool contains(char ch) {
        return children[ch - 'a'] != nullptr;
    }

    void put(char ch, TrieNode* node) {
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

    void insert(const string& word) {
        TrieNode* node = root;
        for (char ch : word) {
            if (!node->contains(ch)) {
                node->put(ch, new TrieNode());
            }
            node = node->get(ch);
        }
        node->markEnd();
    }
};
*/


/*
class Solution {
    vector<string>ans;
    struct TrieNode {
        char c;
        TrieNode* child[26];
        int we;
        TrieNode(char c) {
            this->c=c;
            we=0;
            for(int i =0 ;i<26;i++) {
                child[i]=NULL;
            }
        }
    };
    
    TrieNode* root;
    void insertTrieNode(const string& word) {
       TrieNode *cur = root;
       int idx;
       for(int i = 0;i<word.size();i++) {
        idx = word[i]-'a';
        if(!cur->child[idx]) {
            cur->child[idx] = new TrieNode(char(97+idx));
        }
         cur = cur->child[idx];
       }
       cur->we+=1;
    }

    bool searchInTrie(string s) {
        TrieNode* cur = root;
        for(int i = 0;i<s.size();i++) {
            int idx = s[i] - 'a';
            if(!cur->child[idx]) return false;
            cur = cur->child[idx];
        }
        return cur->we>0;
    }

    void solve(const string & s, string st, int pos) {
        if(pos == s.size()) {
          ans.push_back(st);
          return;
        }
        st += " ";
        for(int i = pos;i<s.size();i++) {
            if(searchInTrie(s.substr(pos,i+1-pos))) {
                solve(s, st+s.substr(pos, i+1-pos),i+1);
            }
        }
    }
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
       root = new TrieNode('/');
       for(auto word: wordDict)
        insertTrieNode(word);
  for(int i = 0;i<s.size();i++){
    if(searchInTrie(s.substr(0,i+1))) {
        solve(s, s.substr(0,i+1),i+1);
    }
  }
       return ans;
    }
};
*/