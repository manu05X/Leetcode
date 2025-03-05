// Disjoint Set Union (DSU) data structure implementation
class DSU {
public:
    int n; // Number of elements in the DSU
    vector<int> parent; // Vector to store the parent of each element
    vector<int> rank;   // Vector to store the rank of each element (used for union by rank)

    // Constructor to initialize the DSU with 'n' elements
    DSU(int n) {
        parent.resize(n); // Resize parent vector to hold 'n' elements
        rank.resize(n, 0); // Resize rank vector to hold 'n' elements, initialized to 0

        // Initialize each element as its own parent (each element is in its own set)
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    // Find function with path compression
    int find(int x) {
        // Traverse up the tree to find the root of 'x'
        // if(parent[x] != x){
        //     parent[x] = find(parent[x]);  // Path compression
        // }
        // return parent[x]; // OR
        while (parent[x] != x) {
            parent[x] = parent[parent[x]];  // Path compression: make 'x' point to its grandparent
            x = parent[x]; // Move 'x' up the tree
        }
        return x; // Return the root of 'x'
    }

    // Union function with rank optimization
    void unionSet(int x, int y) {
        int rootX = find(x); // Find the root of 'x'
        int rootY = find(y); // Find the root of 'y'

        // If 'x' and 'y' are in different sets, merge them
        if (rootX != rootY) {
            // Union by rank: attach the smaller tree under the root of the larger tree
            if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX; // Attach 'y' to 'x'
            } else if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY; // Attach 'x' to 'y'
            } else {
                parent[rootY] = rootX; // If ranks are equal, attach 'y' to 'x' and increase rank of 'x'
                rank[rootX]++;
            }
        }
    }
};

// Solution class to find the number of provinces (connected components) in a graph
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size(); // Number of cities
        DSU dsu(n); // Initialize DSU with 'n' cities

        // Iterate through the adjacency matrix to connect cities
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (isConnected[i][j] == 1) { // If city 'i' is connected to city 'j'
                    dsu.unionSet(i, j); // Union the sets containing 'i' and 'j'
                }
            }
        }

        // Count the number of unique provinces (connected components)
        int provinceCount = 0;
        for (int i = 0; i < n; i++) {
            if (dsu.find(i) == i) { // If 'i' is the root of its set, it represents a unique province
                provinceCount++;
            }
        }

        return provinceCount; // Return the total number of provinces
    }
};



/*-----------------------------------------------------------------------------*/
/*
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
*/


/*
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> parent(n);  // Stores the parent of each node
        vector<int> rank(n, 1); // Stores rank (tree height) for union by rank

        // Step 1: Initialize each node as its own parent
        for (int i = 0; i < n; ++i) {
            parent[i] = i; // Each city is its own parent initially
        }

        // Step 2: Find function with path compression
        int find(int x) {
            if (parent[x] != x) {
                parent[x] = find(parent[x]); // Path compression: make parent[x] point to root
            }
            return parent[x];
        }

        // Step 3: Union function with rank optimization
        void unite(int x, int y) {
            int rootX = find(x);
            int rootY = find(y);

            if (rootX != rootY) { // Only merge if they are in different sets
                if (rank[rootX] > rank[rootY]) {
                    parent[rootY] = rootX; // Attach smaller rank tree under bigger rank tree
                } else if (rank[rootX] < rank[rootY]) {
                    parent[rootX] = rootY;
                } else {
                    parent[rootY] = rootX; // If same rank, attach and increase rank
                    rank[rootX]++;
                }
            }
        }

        // Step 4: Merge connected cities into the same province
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (isConnected[i][j] == 1) { // If two cities are directly connected
                    unite(i, j);
                }
            }
        }

        // Step 5: Count the number of unique parents (provinces)
        int provinceCount = 0;
        for (int i = 0; i < n; ++i) {
            if (find(i) == i) { // If a city is its own root, it's a province
                provinceCount++;
            }
        }

        return provinceCount;
    }
};

*/


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