class Solution {
public:
    vector<vector<int>> allPaths;
    
    void dfs(int node, int end, vector<vector<int>>& graph, vector<vector<int>>& ans, vector<int>& path) {
        // Base case: If the current node is the target node
        if(node == end) {
            ans.push_back(path);
            return;
        }
        
        // Explore all neighbors of the current node
        for(int i = 0; i < graph[node].size(); i++) {
            int nei = graph[node][i];
            path.push_back(nei);  // Add the neighbor to the path
            dfs(nei, end, graph, ans, path);  // Recur for the neighbor
            path.pop_back();  // Backtrack
        }
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;
        int n = graph.size();
        int start = 0;
        int end = n - 1;  // The target node
        vector<int> path = {start};  // Initialize path with the start node
        dfs(start, end, graph, ans, path);  // Start DFS from node 0
        return ans;
    }
};
