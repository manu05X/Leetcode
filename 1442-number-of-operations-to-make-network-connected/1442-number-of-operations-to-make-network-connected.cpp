class DSU {
private:
    vector<int> parent, rank;
public:
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 1);
        for (int i = 0; i < n; ++i){
            parent[i] = i; // Each node is its own parent
        }
    }

    int find(int x) {
        if (parent[x] != x){
            parent[x] = find(parent[x]); // Path compression
        }
        return parent[x];
    }

    bool unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX == rootY) return false; // Already in the same component

        // Union by rank
        if (rank[rootX] > rank[rootY]) {
            parent[rootY] = rootX;
        } else if (rank[rootX] < rank[rootY]) {
            parent[rootX] = rootY;
        } else {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
        return true;
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if (connections.size() < n - 1) return -1; // Not enough cables

        DSU dsu(n);
        int components = n;
        
        for (auto& conn : connections) {
            if (dsu.unite(conn[0], conn[1])) {
                components--; // Reduce number of separate components
            }
        }

        return components - 1; // Minimum operations needed
    }
};

/*

n:4
connections:{{0, 1}, {0, 2}, {1, 2}}
dsu:{parent = {0, 0, 0, 3}, rank = {2, 1, 1, 1}}
components:2
*/