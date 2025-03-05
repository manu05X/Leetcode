class DSU{
public:
    vector<int> parent;
    vector<int> rank;

    DSU(int n){
        rank.resize(n+1,1);
        parent.resize(n+1);

        for(int i = 0; i < n; i++){
            parent[i] = i;
        }
    }

    int find(int x){
        // if(parent[x] != x){
        //     parent[x] = find(parent[x]);
        // }
        // return parent[x];

        while(parent[x] != x){
            parent[x] = parent[parent[x]];
            x = parent[x];
        }
        return x;
    }

    bool unionSet(int x, int y){
        int rootX = find(x);
        int rootY = find(y);

        // If both nodes have the same root, adding this edge creates a cycle
        if(rootX == rootY){
            return false;
        }

        // Union by rank: attach the smaller tree under the root of the larger tree
        if(rank[rootX] > rank[rootY]){
            parent[rootY] = rootX;
        } else if (rank[rootX] < rank[rootY]) {
            parent[rootX] = rootY;
        } else {
            // If ranks are equal, attach 'y' to 'x' and increase rank of 'x'
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

        for(auto& edge : edges){
            // If union returns false, we know the nodes are already connected and hence we can return this edge.
            if(!dsu.unionSet(edge[0], edge[1])){
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