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