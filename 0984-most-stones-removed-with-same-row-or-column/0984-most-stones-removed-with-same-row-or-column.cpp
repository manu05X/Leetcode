class DSU {
private:
    vector<int> parent;
    vector<int> rank;

public:
    // Constructor to initialize parent and rank arrays
    DSU(int size) {
        parent.resize(size);
        rank.resize(size, 0);

        // Initialize each element as its own parent
        for (int i = 0; i < size; i++) {
            parent[i] = i;
        }
    }

    // Find function with path compression
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]); // Path compression
        }
        return parent[x];
    }

    // Union function with rank optimization
    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        // If 'x' and 'y' are in different sets, merge them
        if (rootX != rootY) {
            // Union by rank: attach the smaller tree under the root of the larger tree
            if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            } else if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            } else {
                // If ranks are equal, attach 'y' to 'x' and increase rank of 'x'
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        // Determine the maximum possible value for rows and columns
        int maxRow = 0, maxCol = 0;
        for (auto& stone : stones) {
            maxRow = max(maxRow, stone[0]);
            maxCol = max(maxCol, stone[1]);
        }

        // Initialize DSU with size = maxRow + maxCol + 2 (to handle rows and columns)
        int size = maxRow + maxCol + 10002; // Adding 10002 to handle column offset
        DSU dsu(size);

        // Union rows and columns for each stone
        for (auto& stone : stones) {
            int row = stone[0];
            int col = stone[1] + 10001; // Offset columns to differentiate from rows
            dsu.unite(row, col);
        }

        // Count unique components
        unordered_set<int> uniqueComponents;
        for (auto& stone : stones) {
            uniqueComponents.insert(dsu.find(stone[0]));
        }

        // Maximum stones that can be removed = Total Stones - Connected Components
        return stones.size() - uniqueComponents.size();
    }
};


/*
class DSU {
private:
    unordered_map<int, int> parent;
    unordered_map<int, int> rank;

public:
    // Find function with path compression
    int find(int x) {
        if (parent.find(x) == parent.end()){
            parent[x] = x;
        }

        if (parent[x] != x){
            parent[x] = find(parent[x]); // Path compression
        }
        return parent[x];
    }

    // Union function with rank optimization
    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

         // If 'x' and 'y' are in different sets, merge them
        if (rootX != rootY) {
            // Union by rank: attach the smaller tree under the root of the larger tree
            if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            } else if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            } else {
                // If ranks are equal, attach 'y' to 'x' and increase rank of 'x'
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

*/