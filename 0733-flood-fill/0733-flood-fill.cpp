class Solution {
public:
    int dx[4] = {-1, 1, 0, 0};  // Direction arrays for 4 possible moves (up, down, left, right)
    int dy[4] = {0, 0, -1, 1};

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        // If the color to change is the same as the new color, no operation needed
        if(image[sr][sc] == newColor) {
            return image;
        }

        int currColor = image[sr][sc];  // Original color that needs to be changed
        int n = image.size();
        int m = image[0].size();
        
        // Vector to track visited cells
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        
        // Start DFS to fill the image
        dfs(image, sr, sc, newColor, currColor, visited);

        return image;
    }

    void dfs(vector<vector<int>>& image, int x, int y, int newColor, int currColor, vector<vector<bool>>& visited) {
        // Update the color of the current cell
        image[x][y] = newColor;
        visited[x][y] = true;

        // Explore the 4 possible directions
        for (int i = 0; i < 4; i++) {
            int newX = x + dx[i];
            int newY = y + dy[i];

            // Check if the new coordinates are within bounds and not visited yet, and the color matches the original color
            if (newX >= 0 && newX < image.size() && newY >= 0 && newY < image[0].size() && !visited[newX][newY] && image[newX][newY] == currColor) {
                dfs(image, newX, newY, newColor, currColor, visited);  // Recur for the next cell
            }
        }
    }
};



/*
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        ios_base::sync_with_stdio(false);  
        cin.tie(NULL);
        
        if(image[sr][sc] == newColor){
            return image;
        }
        backtrackFlood(image,image[sr][sc],sr, sc, newColor);

        return image;
    }

    void backtrackFlood(vector<vector<int>>& image, int color ,int sr, int sc, int newColor)
    {
        if(sc < 0 || sr < 0 || sr >= image.size() || sc >= image[0].size() || image[sr][sc] != color)
        {
            return;
        }
        image[sr][sc] = newColor;

        int topRow = sr-1;
        int bottomRow = sr+1;
        int rightCol = sc + 1;
        int leftCol = sc-1;

        backtrackFlood(image, color, topRow, sc, newColor);
        backtrackFlood(image, color, bottomRow, sc, newColor);
        backtrackFlood(image, color, sr, rightCol, newColor);
        backtrackFlood(image, color, sr, leftCol, newColor);

    }
};
*/