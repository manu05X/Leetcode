class DSU{
public:
    int n;
    vector<int> parent;
    vector<int> rank;

    DSU(int n){
        parent.resize(n);
        rank.resize(n,0);

        // Initialize each city as its own parent
        for(int i = 0; i < n; i++){
            parent[i] = i;
        }
    }

    // Find function with path compression
    int find(int x){
        // if(parent[x] != x){
        //     parent[x] = find(parent[x]);  // Path compression
        // }
        // return parent[x]; // OR
        while(parent[x] != x){
            parent[x] = parent[parent[x]];  // Path compression
            x = parent[x];
        }

        return x;
    }

    // Union function with rank optimization
    void unionSet(int x, int y){
        int rootX = find(x);
        int rootY = find(y);

        if(rootX != rootY){
            if(rank[rootX] > rank[rootY]){
                parent[rootY] = rootX;
            } else if(rank[rootX] < rank[rootY]){
                parent[rootX] = rootY;
            } else{
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }
};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        DSU dsu(n);

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(isConnected[i][j] == 1){
                    dsu.unionSet(i,j);
                }
            }
        }

        int provinceCount = 0;
        for(int i = 0; i < n; i++){
            if(dsu.find(i) == i){
                provinceCount++;
            }
        }

        return provinceCount;
    }
};