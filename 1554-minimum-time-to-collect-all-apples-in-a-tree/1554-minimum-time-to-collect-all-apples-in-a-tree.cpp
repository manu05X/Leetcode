class Solution {
public:
    int dfs(int node, int parent, vector<vector<int>>& adj, vector<bool>& hasApple){
        int totalTime = 0, childTime = 0;

        for(auto child : adj[node]){
            if(child == parent){
                continue;
            }

            childTime = dfs(child, node, adj, hasApple);

            if(childTime || hasApple[child]){
                totalTime += childTime+2;
            }
        }

        return totalTime;
    }

    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>> adj(n);

        for(auto& edge : edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        int ans = dfs(0, -1, adj, hasApple);

        return ans;
    }
};

/*

edges =    [[0,1],[0,2],[1,4],[1,5],[2,3],[2,6]]
hasApple = [false,false,true,false,true,true,false]

0 -> 1,2
1 -> 4,5
2 -> 3,6

*/