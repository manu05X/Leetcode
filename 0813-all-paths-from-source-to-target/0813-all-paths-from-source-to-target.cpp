class Solution {
public:
    vector<vector<int>> allPaths;
    
    void dfs(int node, vector<int>& temPath, vector<vector<int>>& graph) {
        // Add the current node to the path
        temPath.push_back(node);

        // If we reached the last node (node n-1), add the current path to the result
        if (node == graph.size() - 1) {
            allPaths.push_back(temPath);
        } else {
            // Explore all neighbors of the current node
            for (int i = 0; i < graph[node].size(); i++) {
                dfs(graph[node][i], temPath, graph);
            }
        }
        
        // Backtrack: remove the current node from the path
        temPath.pop_back();
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> temPath;
        dfs(0, temPath, graph);
        return allPaths;
    }
};
