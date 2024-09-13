#include <vector>
#include <list>
#include <unordered_map>

using namespace std;

class Solution {
public:
    class Graph {
        int v;
        list<int> *l;

    public:
        Graph(int v) {
            this->v = v;
            l = new list<int>[v];
        }

        void addEdge(int u, int v) {
            l[u].push_back(v);
        }

        bool dfs(int src, vector<bool>& vis, vector<bool>& st) {
            vis[src] = true;
            st[src] = true;
            for (auto nbr : l[src]) {
                if (!vis[nbr]) {
                    bool nbrFoundACycle = dfs(nbr, vis, st);
                    if (nbrFoundACycle) {
                        return true;
                    }
                } else if (st[nbr]) {
                    return true;
                }
            }
            st[src] = false;
            return false;
        }
    };

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        Graph g(numCourses); // Initialize graph with numCourses vertices
        
        // Mark all vertices as not visited
        vector<bool> vis(numCourses, false);
        vector<bool> st(numCourses, false);
        
        // Add edges to the graph
        for (const auto& edge : prerequisites) {
            g.addEdge(edge[0], edge[1]);
        }
        
        // Check for cycles in the graph
        for (int i = 0; i < numCourses; i++) {
            if (!vis[i]) {
                bool nbrFoundACycle = g.dfs(i, vis, st);
                if (nbrFoundACycle) {
                    return false;
                }
            }
        }
        return true;
    }
};
