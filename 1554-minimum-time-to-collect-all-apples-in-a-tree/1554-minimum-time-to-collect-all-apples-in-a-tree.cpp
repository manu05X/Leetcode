class Solution {
public:
    // Helper function to perform DFS and calculate the minimum time to collect all apples.
    int dfs(int currNode, int parent, vector<vector<int>>& adj, vector<bool>& hasApple) {
        int totalTime = 0, childTime = 0;  // totalTime keeps track of the total time for this subtree.

        // Traverse all child nodes of the current node
        for (auto child : adj[currNode]) {
            if (child == parent) {  
                // If the child is the parent, skip it to prevent traversing back
                continue;
            }

            // Recursively call DFS for the child node
            childTime = dfs(child, currNode, adj, hasApple);

            // If the subtree rooted at 'child' contains an apple or contributes time,
            // then we add the time to visit and return from this child (2 units)
            if (childTime > 0 || hasApple[child]) {
                totalTime += childTime + 2;
            }
        }

        return totalTime;  // Return the total time required for this subtree
    }

    // Main function to find the minimum time required to collect all apples
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>> adj(n);  // Create adjacency list representation of the tree

        // Convert edge list to adjacency list
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        // Start DFS from the root node (0), with no parent (-1)
        int ans = dfs(0, -1, adj, hasApple);

        return ans;  // Return the minimum time required to collect all apples
    }
};


/*

edges =    [[0,1],[0,2],[1,4],[1,5],[2,3],[2,6]]
hasApple = [false,false,true,false,true,true,false]

0 -> 1,2
1 -> 4,5
2 -> 3,6

*/