class Solution {
public:
    // DFS function to perform flood fill
    void dfs(vector<vector<int>>& image, int i, int j, int originalColor, int newColor) {
        int n = image.size();
        int m = image[0].size();

        // Base case: If the current cell is out of bounds or does not have the original color, return
        if (i < 0 || i >= n || j < 0 || j >= m || image[i][j] != originalColor) {
            return;
        }

        // Change the color of the current cell to the new color
        image[i][j] = newColor;

        // Recursively visit all four neighboring cells (up, down, left, right)
        dfs(image, i - 1, j, originalColor, newColor); // up
        dfs(image, i + 1, j, originalColor, newColor); // down
        dfs(image, i, j - 1, originalColor, newColor); // left
        dfs(image, i, j + 1, originalColor, newColor); // right
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int originalColor = image[sr][sc]; // Get the original color of the starting pixel

        // If the original color is the same as the new color, no need to perform flood fill
        if (originalColor != newColor) {
            dfs(image, sr, sc, originalColor, newColor);
        }

        return image;
    }
};


/*
class Solution {
public:
    int dx[4] = {-1, 1, 0, 0};  // Direction arrays for 4 possible moves (up, down, left, right)
    int dy[4] = {0, 0, -1, 1};

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        ios_base::sync_with_stdio(false);  
        cin.tie(NULL);
        
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
*/