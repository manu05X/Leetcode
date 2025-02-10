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