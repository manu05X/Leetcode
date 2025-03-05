// Disjoint Set Union (DSU) data structure implementation
class DSU {
public:
    int n; // Number of elements in the DSU
    vector<int> parent; // Vector to store the parent of each element
    vector<int> rank;   // Vector to store the rank of each element (used for union by rank)

    // Constructor to initialize the DSU with 'n' elements
    DSU(int n) {
        parent.resize(n); // Resize parent vector to hold 'n' elements
        rank.resize(n, 0); // Resize rank vector to hold 'n' elements, initialized to 0

        // Initialize each element as its own parent (each element is in its own set)
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    // Find function with path compression
    int find(int x) {
        // Traverse up the tree to find the root of 'x'
        while (parent[x] != x) {
            parent[x] = parent[parent[x]];  // Path compression: make 'x' point to its grandparent
            x = parent[x]; // Move 'x' up the tree
        }
        return x; // Return the root of 'x'
    }

    // Union function with rank optimization
    void unionSet(int x, int y) {
        int rootX = find(x); // Find the root of 'x'
        int rootY = find(y); // Find the root of 'y'

        // If 'x' and 'y' are in different sets, merge them
        if (rootX != rootY) {
            // Union by rank: attach the smaller tree under the root of the larger tree
            if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX; // Attach 'y' to 'x'
            } else if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY; // Attach 'x' to 'y'
            } else {
                parent[rootY] = rootX; // If ranks are equal, attach 'y' to 'x' and increase rank of 'x'
                rank[rootX]++;
            }
        }
    }
};

// Solution class to find the number of provinces (connected components) in a graph
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size(); // Number of cities
        DSU dsu(n); // Initialize DSU with 'n' cities

        // Iterate through the adjacency matrix to connect cities
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (isConnected[i][j] == 1) { // If city 'i' is connected to city 'j'
                    dsu.unionSet(i, j); // Union the sets containing 'i' and 'j'
                }
            }
        }

        // Count the number of unique provinces (connected components)
        int provinceCount = 0;
        for (int i = 0; i < n; i++) {
            if (dsu.find(i) == i) { // If 'i' is the root of its set, it represents a unique province
                provinceCount++;
            }
        }

        return provinceCount; // Return the total number of provinces
    }
};