class DSU {
private:
    unordered_map<string, string> parent;
    unordered_map<string, int> rank;

public:
    string find(string x) {
        if (parent[x] != x) 
            parent[x] = find(parent[x]); // Path compression
        return parent[x];
    }

    void unite(string x, string y) {
        string rootX = find(x);
        string rootY = find(y);
        if (rootX != rootY) {
            if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            } else if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            } else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }

    void add(string x) {
        if (parent.find(x) == parent.end()) {
            parent[x] = x;
            rank[x] = 1;
        }
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        DSU dsu;
        unordered_map<string, string> emailToName;
        
        // Step 1: Initialize DSU and map emails to names
        for (auto& acc : accounts) {
            string name = acc[0];
            for (int i = 1; i < acc.size(); i++) {
                dsu.add(acc[i]);  // Initialize DSU
                emailToName[acc[i]] = name;
                if (i > 1) dsu.unite(acc[1], acc[i]); // Union all emails in the same account
            }
        }
        
        // Step 2: Group emails by their root parent
        unordered_map<string, vector<string>> mergedAccounts;
        for (auto& [email, _] : emailToName) {
            mergedAccounts[dsu.find(email)].push_back(email);
        }
        
        // Step 3: Prepare the result
        vector<vector<string>> result;
        for (auto& [root, emails] : mergedAccounts) {
            sort(emails.begin(), emails.end()); // Sort emails
            emails.insert(emails.begin(), emailToName[root]); // Add name
            result.push_back(emails);
        }
        
        return result;
    }
};
