class Solution {
public:
    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,-1,1};
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        ios_base::sync_with_stdio(false);  
        cin.tie(NULL);

        int n = image.size();
        int m = image[0].size();

        if(image[sr][sc] == newColor){
            return image;
        }
        
        int currColor = image[sr][sc];
        vector<vector<bool>> visited(n, vector<bool>(m,false));
        dfs(image, sr,sc,newColor, currColor ,visited);

        return image;

    }

    void dfs(vector<vector<int>>& image, int sr, int sc, int newColor, int currColor, vector<vector<bool>>& visited){
        image[sr][sc] = newColor;
        visited[sr][sc] = true;

        for(int i = 0; i < 4; i++){
            int newX = sr+dx[i];
            int newY = sc+dy[i];

            if(newX >= 0 && newX < image.size() && newY >= 0 && newY < image[0].size() && visited[newX][newY] == false && image[newX][newY] == currColor){
                 dfs(image, newX, newY, newColor, currColor, visited);
            }
        }
        
    }
};