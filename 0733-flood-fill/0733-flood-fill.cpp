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