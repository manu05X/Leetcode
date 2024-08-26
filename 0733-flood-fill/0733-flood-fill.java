class Solution {
    int n, m;
    int dx[] = {0,0,1,-1};
    int dy[] = {1,-1,0,0};
    int startColor;
     public void dfs(int[][] image, int x, int y, int newColor, boolean[][] visited){
        // give current position a color
        image[x][y] = newColor;
         // mark current position as visited
        visited[x][y] = true;
         // traverse all 4 directions
        for(int i = 0; i < 4; i++){
            int newX = x+dx[i];
            int newY = y+dy[i];

            if(newX >= 0 && newY >= 0 && newX < n && newY < m && visited[newX][newY] == false && image[newX][newY] == startColor){
                // calling dfs to fill adjacent cells
                dfs(image, newX, newY, newColor, visited);
            }
        }
     }
   
    public int[][] floodFill(int[][] image, int sr, int sc, int newColor) {
        n = image.length;
        m = image[0].length;
        // get the starting color
        startColor = image[sr][sc];
        // make a visited 2-D array to keep track of visited element
        boolean[][] visited = new boolean[n][m];

        // Call dfs to fill all those cells
        dfs(image, sr, sc, newColor, visited);
        return image;
    }
}