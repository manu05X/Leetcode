class Solution {
public:
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        // Create vectors to store representative, size, and minimum weight for each node
        vector<int> f(n), size(n, 1), W(n, INT_MAX), result(query.size());

        // Initialize each node's representative to itself
        for (int i = 0; i < n; ++i) {
            f[i] = i;
        }

        // Process each edge to combine nodes and update minimum weight
        for (auto& edge : edges) {
            combine(edge[0], edge[1], edge[2], f, size, W);
        }

        // Process each query to find minimum weight or if nodes are in the same component
        for (int i = 0; i < query.size(); ++i) {
            if (query[i][0] == query[i][1]) {
                result[i] = 0; // If query involves the same node, weight is 0
            } else {
                // Find representatives of nodes in the query
                int u = find(query[i][0], f), v = find(query[i][1], f);
                // If nodes are in the same component, get minimum weight, otherwise return -1
                result[i] = u == v ? W[u] : -1;
            }
        }

        return result; // Return the result
    }

private:
    // Find representative of a node using path compression
    int find(int u, vector<int>& representative) {
        if (u == representative[u])
            return u;
        else
            return representative[u] = find(representative[u], representative);
    }

    // Combine two nodes into the same component and update minimum weight
    void combine(int u, int v, int w, vector<int>& representative, vector<int>& size, vector<int>& W) {
        u = find(u, representative);
        v = find(v, representative);

        if (u == v) {
            W[u] &= w; // If nodes are already in the same component, update minimum weight
            return;
        } else {
            if (size[u] > size[v]) {
                representative[v] = u; // Set u as representative of v
                size[u] += size[v]; // Update size of component
                W[u] &= W[v] & w; // Update minimum weight
            } else {
                representative[u] = v; // Set v as representative of u
                size[v] += size[u]; // Update size of component
                W[v] &= W[u] & w; // Update minimum weight
            }
        }
    }
};
