class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();

        vector<vector<int>> visited = grid;

        queue<pair<int, int>> q;
        int countFreshOranges = 0;
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                if(visited[i][j] == 2)
                {
                    q.push({i,j});
                }
                if(visited[i][j] == 1){
                    countFreshOranges++;
                }
            }
        }
        if(countFreshOranges == 0)
            return 0;
        if(q.empty())
            return -1;
        
        int minutes = -1;
        // we will cover four directions i.e. up, down, left, right
        vector<pair<int, int>> dirs = {{1, 0},{-1, 0},{0, -1},{0, 1}};
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                auto [x,y] = q.front();
                q.pop();
                for(auto [dx,dy]: dirs){
                    int i = x+dx;
                    int j = y+dy;
                    if (i >= 0 && i < r && j >= 0 && j < c && visited[i][j] == 1) {
                        visited[i][j] = 2;
                        countFreshOranges--;
                        q.push({i, j});
                    }
                }
            }
            minutes++;
        }
        if(countFreshOranges == 0)
            return minutes;
        return -1;
    }
};