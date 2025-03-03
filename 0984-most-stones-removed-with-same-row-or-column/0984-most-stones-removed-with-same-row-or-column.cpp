class DSU {
private:
    unordered_map<int, int> parent;
    unordered_map<int, int> rank;

public:
    // Find function with path compression
    int find(int x) {
        if (parent.find(x) == parent.end()) parent[x] = x;
        if (parent[x] != x) parent[x] = find(parent[x]); // Path compression
        return parent[x];
    }

    // Union function with rank optimization
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
    int removeStones(vector<vector<int>>& stones) {
        DSU dsu;
        unordered_set<int> uniqueComponents;

        for (auto& stone : stones) {
            int row = stone[0];
            int col = stone[1] + 10001; // Offset columns to differentiate from rows
            dsu.unite(row, col);
        }

        // Count unique components
        for (auto& stone : stones) {
            uniqueComponents.insert(dsu.find(stone[0]));
        }

        // Maximum stones that can be removed = Total Stones - Connected Components
        return stones.size() - uniqueComponents.size();
    }
};
