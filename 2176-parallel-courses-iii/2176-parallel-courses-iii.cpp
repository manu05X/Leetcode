class Solution {
public:
    unordered_map<int, vector<int>> graph;
    vector<int> memo;
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        //Create a graph from relations
        for(vector<int>& edge: relations){
            //For convenience, we will change the nodes to be 0-indexed.
            int x = edge[0]-1;
            int y = edge[1]-1;
            graph[x].push_back(y);
        }

        memo = vector(n,-1);
        int ans = 0;

        //Call dfs(node) for all nodes and return the maximum value.
        for(int node = 0; node < n; node++){
            ans = max(ans, dfs(node, time));
        }
        return ans;
    }

    //Define a memoized function dfs(node)
    int dfs(int node, vector<int>& time) {
        //If node has no outgoing edges, return time[node]
        if (memo[node] != -1) {
            return memo[node];
        }
        
        if (graph[node].size() == 0) {
            return time[node];
        }
        
        int ans = 0;
        //Iterate over graph[node]
        for (int neighbor: graph[node]) {
            //For each neighbor, set ans = max(ans, dfs(neighbor)).
            ans = max(ans, dfs(neighbor, time));
        }
        
        memo[node] = time[node] + ans;
        //Return time[node] + ans.
        return time[node] + ans;
    }
    
};