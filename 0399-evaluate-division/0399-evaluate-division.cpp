// Graph Union and Find
class Solution {
private:
    unordered_map<string, string> parent;
    unordered_map<string, double> weight;

    string find(const string &x) {
        if (parent.find(x) == parent.end()) {
            parent[x] = x;
            weight[x] = 1.0;
            return x;
        }
        if (parent[x] == x) return x;

        string root = find(parent[x]);
        weight[x] *= weight[parent[x]];
        parent[x] = root;
        return root;
    }

    void unionSet(const string &a, const string &b, double val) {
        string rootA = find(a);
        string rootB = find(b);
        if (rootA != rootB) {
            parent[rootA] = rootB;
            weight[rootA] = (weight[b] * val) / weight[a];
        }
    }

public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        // Step 1: Build the Union-Find structure.
        for (int i = 0; i < equations.size(); i++) {
            string a = equations[i][0], b = equations[i][1];
            double val = values[i];
            unionSet(a, b, val);
        }

        // Step 2: Process each query.
        vector<double> result;
        for (auto &q : queries) {
            string x = q[0], y = q[1];
            if (parent.find(x) == parent.end() || parent.find(y) == parent.end()) {
                result.push_back(-1.0);
                continue;
            }

            string rootX = find(x);
            string rootY = find(y);
            if (rootX != rootY) {
                result.push_back(-1.0);
            } else {
                result.push_back(weight[x] / weight[y]);
            }
        }
        return result;
    }
};



/*
//BFS
class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        // Step 1: Build the adjacency list (graph).
        unordered_map<string, vector<pair<string, double>>> adj;
        for (int i = 0; i < equations.size(); i++) {
            string u = equations[i][0], v = equations[i][1];
            double val = values[i];
            adj[u].push_back({v, val}); // Forward edge: u/v = val.
            adj[v].push_back({u, 1.0 / val}); // Reverse edge: v/u = 1/val.
        }

        // Step 2: Process each query using BFS.
        vector<double> result;
        for (auto &q : queries) {
            string src = q[0], dest = q[1];
            double ans = -1.0; // Default if src/dest not found.

            if (adj.find(src) != adj.end() && adj.find(dest) != adj.end()) {
                queue<pair<string, double>> q_bfs; // Queue for BFS: (node, current_product).
                q_bfs.push({src, 1.0});
                unordered_set<string> visited;
                visited.insert(src);

                while (!q_bfs.empty()) {
                    auto [current, product] = q_bfs.front();
                    q_bfs.pop();

                    if (current == dest) {
                        ans = product;
                        break; // Early termination if destination is found.
                    }

                    for (auto [neighbor, weight] : adj[current]) {
                        if (visited.find(neighbor) == visited.end()) {
                            visited.insert(neighbor);
                            q_bfs.push({neighbor, product * weight});
                        }
                    }
                }
            }
            result.push_back(ans);
        }
        return result;
    }
};
*/




/*
//DFS
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
*/