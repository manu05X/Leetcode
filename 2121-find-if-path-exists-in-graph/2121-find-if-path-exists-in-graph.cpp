class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int src, int dest) {
        vector<int> adj[n];
        for(int i = 0; i < edges.size(); i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        queue<int> q;
        q.push(src);
        vector<int>vis(n,false);
        while(!q.empty())
        {
            int node = q.front();
            if(vis[dest])
                return true;
            
            q.pop();
            vis[node] = true;
            for(int it : adj[node])
            {
                if(!vis[it])
                {
                    q.push(it);
                    vis[it] = true;
                }
            }
        }
        return vis[dest];
    }
};