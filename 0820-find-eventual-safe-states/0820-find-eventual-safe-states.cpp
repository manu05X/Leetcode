class Solution {
public:
    // DFS function to check if a node is safe
    bool dfs(int node, vector<vector<int>>& graph, vector<int>& visited) {
        // If the node is already in the visiting state, it's part of a cycle (not safe)
        if (visited[node] == 1) {
            return false;
        }

        // If the node is already marked as safe, return true
        if (visited[node] == 2) {
            return true;
        }

        // Mark the node as visiting
        visited[node] = 1;

        // Traverse all neighbors of the current node
        for (int neighbor : graph[node]) {
            // If any neighbor is not safe, the current node is not safe
            if (!dfs(neighbor, graph, visited)) {
                return false;
            }
        }

        // If all neighbors are safe, mark the current node as safe
        visited[node] = 2;
        return true;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> visited(n, 0); // 0: unvisited, 1: visiting, 2: visited and safe
        vector<int> safeNodes;

        // Perform DFS for each unvisited node
        for (int i = 0; i < n; i++) {
            if (dfs(i, graph, visited)) {
                safeNodes.push_back(i); // Add safe nodes to the result
            }
        }

        return safeNodes;
    }
};



/*
class Solution {
public:
    bool dfs(int node,vector<int> &visited,vector<int> &pathVisited,vector<int> &checked,vector<vector<int>> &graph)
    {
        visited[node]=1;
        pathVisited[node]=1;

        for(int nei : graph[node])
        {
            if(!visited[nei])
            {
                if(dfs(nei,visited,pathVisited,checked,graph))
                {
                    return true;
                }
            }
              else if(pathVisited[nei]==1)
                {
                    return true;
                }
        }
        checked[node]=1;
        pathVisited[node]=0;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
     int n = graph.size();
     vector<int> visited(n,0);
     vector<int> pathVisited(n,0);
     vector<int> checked(n,0);
     vector<int> safe;

     for(int i=0;i<n;i++)
     {
        if(!visited[i])
        {
            dfs(i,visited,pathVisited,checked,graph);
        }
     }

     for(int i=0;i<n;i++)
     {
        if(checked[i]==1)
        safe.push_back(i);
     }
     return safe;
    }
};

*/

/*
class Solution {
public:
    int n;
    vector<int> degreein;
    vector< vector<int> > rGraph;
    vector<int> ans;
    
    void init(vector<vector<int>>& G){
        n = G.size();
        degreein = vector<int>(n,0);
        rGraph.resize(n, vector<int>(0) );
        
        for (int u=0; u<n; u++){
            for (int v:G[u]){
                rGraph[v].push_back(u);
                degreein[u]++;
            }
        }
    }
    
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        init(graph);
        queue<int> que;
        for (int i=0; i<n; i++){
            if (degreein[i]==0) que.push(i);
        }
        while (que.size()){
            int u = que.front(); que.pop();
            ans.push_back(u);
            for (int v:rGraph[u]){
                degreein[v]--;
                if (degreein[v]==0) que.push(v);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};
*/

/*

[0 = [1,2], 1 = [2,3], 2 = [5], 3 = [0], 4 = [5], 5 = [],6 = []]

*/