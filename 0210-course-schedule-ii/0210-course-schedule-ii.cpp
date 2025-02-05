class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // Step 1: Build the adjacency list and in-degree array
        vector<vector<int>> adj(numCourses);
        vector<int> inDegree(numCourses, 0);

        for (const auto& pre : prerequisites) {
            int src = pre[1]; // prerequisite task
            int dest = pre[0]; // dependent task

            adj[src].push_back(dest); // Edge from u -> v
            inDegree[dest]++;       // Increase indegree of v (incoming edge u -> v)
        }

        // Step 2: Initialize the queue with nodes having in-degree 0
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }

        // Step 3: Perform topological sort using BFS
        vector<int> ans;
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            ans.push_back(curr);

            // Visit all the neighbors of the current node
            for (int neighbor : adj[curr]) {
                inDegree[neighbor]--;

                if (inDegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        // Step 4: If all courses are processed, return order; else return an empty vector
        return ans.size() == numCourses ? ans : vector<int>();
    }
};