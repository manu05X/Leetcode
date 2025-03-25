class Solution {
public:
    // DFS to find a path from src to dest and compute the product of edge weights.
    void dfs(unordered_map<string, vector<pair<string, double>>> &adj, string src, string dest, unordered_set<string>& visited, double product, double &ans) {
        if(visited.find(src) != visited.end()) 
            return; // Skip visited nodes.

        visited.insert(src);
        if(src == dest) {
            ans = product; // Store result if destination is reached.
            return;
        }

        // Traverse all neighbors of src.
        for(auto p : adj[src]) {
            string v = p.first;
            double val = p.second;
            dfs(adj, v, dest, visited, product * val, ans); // Multiply edge weights.
        }
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        // Step 1: Build the adjacency list (graph).
        unordered_map<string, vector<pair<string, double>>> adj;
        for(int i = 0; i < equations.size(); i++) {
            string u = equations[i][0];
            string v = equations[i][1];
            double val = values[i];

            adj[u].push_back({v, val}); // Forward edge: u/v => value i.e a/b => value
            adj[v].push_back({u, 1.0/val}); //Reverse edge:  v/u => value i.e b/a => 1/value
        }

        // Step 2: Process each query.
        vector<double> result;
        for(auto &q : queries) {
            string src = q[0];
            string dest = q[1];

            double ans = -1.0; // Default if src/dest not found.

            if(adj.find(src) != adj.end()) {
                unordered_set<string> visited;
                dfs(adj, src, dest, visited, 1.0, ans); // Start DFS with product = 1.0.
            }
            result.push_back(ans);
        }
        return result;
    }
};