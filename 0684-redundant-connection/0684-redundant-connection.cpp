class DSU {
private:
    vector<int> parent;
    vector<int> rank;

public:
    // Constructor to initialize DSU
    DSU(int n) {
        parent.resize(n + 1); // n+1 to accommodate 1-based indexing
        rank.resize(n + 1, 1);
        for (int i = 1; i <= n; ++i) {
            parent[i] = i; // Each node is its own parent initially
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
    bool unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX == rootY) {
            return false; // If both nodes have the same root, adding this edge creates a cycle
        }

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
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        DSU dsu(n);

        for (auto& edge : edges) {
            if (!dsu.unite(edge[0], edge[1])) {
                return edge; // This edge forms a cycle, return it
            }
        }

        return {}; // This should never be reached
    }
};




/*
class Solution {
private:
    // Performs DFS and returns true if there's a path between src and target.
    bool isConnected(int src, int target, vector<bool>& visited,
                     vector<int> adjList[]) {
        visited[src] = true;

        if (src == target) {
            return true;
        }

        int isFound = false;
        for (int adj : adjList[src]) {
            if (!visited[adj]) {
                isFound = isFound || isConnected(adj, target, visited, adjList);
            }
        }

        return isFound;
    }

public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int N = edges.size();

        vector<int> adjList[N];
        for (auto edge : edges) {
            vector<bool> visited(N, false);

            // If DFS returns true, we will return the edge.
            if (isConnected(edge[0] - 1, edge[1] - 1, visited, adjList)) {
                return edge;
            }

            adjList[edge[0] - 1].push_back(edge[1] - 1);
            adjList[edge[1] - 1].push_back(edge[0] - 1);
        }

        return {};
    }
};
*/