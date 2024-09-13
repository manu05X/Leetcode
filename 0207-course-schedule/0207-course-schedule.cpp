#include <vector>
#include <list>
#include <unordered_map>

using namespace std;

class Solution {
public:
    class Graph {
        int v; // Number of vertices
        list<int> *l; // Adjacency list for storing the graph

    public:
        // Constructor to initialize the graph with v vertices
        Graph(int v) {
            this->v = v;
            l = new list<int>[v]; // Create an array of lists for adjacency list representation
        }

        // Add a directed edge from u to v
        void addEdge(int u, int v) {
            l[u].push_back(v); // Add v to the adjacency list of u
        }

        // Depth-First Search (DFS) to detect cycles
        bool dfs(int src, vector<bool>& vis, vector<bool>& st) {
            vis[src] = true; // Mark the current node as visited
            st[src] = true; // Mark the current node as in the recursion stack
            
            // Explore all neighbors of the current node
            for (auto nbr : l[src]) {
                if (!vis[nbr]) { // If neighbor has not been visited
                    // Recursively perform DFS
                    bool nbrFoundACycle = dfs(nbr, vis, st);
                    if (nbrFoundACycle) {
                        return true; // Cycle detected
                    }
                } else if (st[nbr]) { // If the neighbor is already in the recursion stack
                    return true; // Cycle detected
                }
            }
            
            // Unmark the current node as in the recursion stack
            st[src] = false;
            return false; // No cycle found for this path
        }
    };

    // Function to check if it's possible to finish all courses
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        Graph g(numCourses); // Initialize the graph with numCourses vertices
        
        // Mark all vertices as not visited
        vector<bool> vis(numCourses, false);
        vector<bool> st(numCourses, false);
        
        // Add edges to the graph based on prerequisites
        for (const auto& edge : prerequisites) {
            g.addEdge(edge[0], edge[1]); // Add a directed edge from edge[0] to edge[1]
        }
        
        // Check for cycles in the graph
        for (int i = 0; i < numCourses; i++) {
            if (!vis[i]) { // If vertex i has not been visited
                bool nbrFoundACycle = g.dfs(i, vis, st); // Perform DFS to check for cycles
                if (nbrFoundACycle) {
                    return false; // Cycle detected, cannot finish all courses
                }
            }
        }
        return true; // No cycles detected, all courses can be finished
    }
};
