class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> parent(n);
        vector<int> rank(n, 1);

        // Initialize each city as its own parent
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }

        // Find function with path compression
        auto find = [&](int x) {
            while (parent[x] != x) {
                parent[x] = parent[parent[x]]; // Path compression
                x = parent[x];
            }
            return x;
        };

        // Union function with rank optimization
        auto unite = [&](int x, int y) {
            int rootX = find(x);
            int rootY = find(y);

            if (rootX != rootY) {
                if (rank[rootX] > rank[rootY]) {
                    parent[rootY] = rootX;
                } else if (rank[rootX] < rank[rootY]) {
                    parent[rootX] = rootY;
                } else {
                    parent[rootY] = rootX;
                    rank[rootX]++;
                }
            }
        };

        // Perform union operations for connected cities
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (isConnected[i][j] == 1) {
                    unite(i, j);
                }
            }
        }

        // Count the number of unique parents (provinces)
        int provinceCount = 0;
        for (int i = 0; i < n; ++i) {
            if (parent[i] == i) { // If the city is its own parent, it's a root
                provinceCount++;
            }
        }

        return provinceCount;
    }
};


/*
class Solution {
public:
    void dfs(int node, vector<vector<int>>& isConnected, vector<bool>& visit) {
        visit[node] = true;
        for(int i = 0; i < isConnected.size(); i++){
            if(isConnected[node][i] == 1 && visit[i] == false){
                dfs(i, isConnected, visit);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int numberOfComponents = 0;
        vector<bool> visit(n);

        for (int i = 0; i < n; i++) {
            if (!visit[i]) {
                numberOfComponents++;
                dfs(i, isConnected, visit);
            }
        }

        return numberOfComponents;
    }
};


*/



/*
class Solution {
public:
    void bfs(int node, vector<vector<int>>& isConnected, vector<bool>& visit){
        queue<int> q;
        q.push(node);

        visit[node] = true;

        while(!q.empty()){
            int x = q.front();
            q.pop();

            for(int i = 0; i < isConnected.size(); i++){
                if(isConnected[x][i] && !visit[i]){
                    q.push(i);
                    visit[i] = true;
                }
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int count = 0;
        vector<bool> visit(n);

        for(int i = 0; i < n; i++){
            if(!visit[i]){
                count++;
                bfs(i, isConnected, visit);
            }
        }

        return count;
    }
};

*/