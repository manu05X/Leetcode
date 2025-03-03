class DSU {
private:
    vector<int> parent, rank;
public:
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 1);
        for (int i = 0; i < n; ++i) parent[i] = i;
    }

    int find(int x) {
        if (parent[x] != x) parent[x] = find(parent[x]); // Path compression
        return parent[x];
    }

    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
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
};

class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        DSU dsu(26); // 26 lowercase letters
        
        // **Step 1: Process "==" equations**
        for (auto& eq : equations) {
            if (eq[1] == '=') {
                int var1 = eq[0] - 'a';
                int var2 = eq[3] - 'a';
                dsu.unite(var1, var2);
            }
        }
        
        // **Step 2: Process "!=" equations**
        for (auto& eq : equations) {
            if (eq[1] == '!') {
                int var1 = eq[0] - 'a';
                int var2 = eq[3] - 'a';
                if (dsu.find(var1) == dsu.find(var2)) return false; // Contradiction found
            }
        }

        return true; // No contradictions found
    }
};
