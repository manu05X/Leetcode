class Solution {
    public int[][] generateMatrix(int n) {
        int[][] result = new int[n][n];
        int cnt = 1;
        int dir[][] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int d = 0;
        int row = 0;
        int col = 0;
        while (cnt <= n * n) {
            result[row][col] = cnt++;
            int r = Math.floorMod(row + dir[d][0], n);
            int c = Math.floorMod(col + dir[d][1], n);

            // change direction if next cell is non zero
            if (result[r][c] != 0) d = (d + 1) % 4;

            row += dir[d][0];
            col += dir[d][1];
        }
        return result;
    }
}
/*<-------------------------------------METHOD 2--------------------------------------------------------------------------------->*/
class Solution {
    public int[][] generateMatrix(int n) {
        int r1 = 0, r2 = n-1;
        int c1 = 0, c2 = n-1;
        int cnt = 0;
        
        int[][] res = new int[n][n];
        
        while(r1 <= r2 && c1 <= c2)
        {
            for(int i = c1; i <= c2; i++){
                res[r1][i] = ++cnt;
            }
            
            for(int i = r1+1; i<=r2; i++){
                res[i][c2] = ++cnt;
            }
            
            for(int i = c2-1; i>= c1; i--){
                res[r2][i] = ++cnt;
            }
            for(int i = r2-1; i > r1; i--){
                res[i][c1] = ++cnt;
            }
            
            r1++;
            c1++;
            r2--;
            c2--;
            
        }
        return res;
    }
}
