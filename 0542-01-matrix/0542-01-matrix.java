class Solution {
    public int[][] updateMatrix(int[][] mat) {
        int n = mat.length;
        int m = mat[0].length;

        int[][] directions = {{0,1},{0,-1}, {1, 0}, {-1, 0}};
        Queue<int[]> q = new ArrayDeque<>();

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(mat[i][j] == 0){
                    q.add(new int[]{i,j});
                } else {
                    mat[i][j] = Integer.MAX_VALUE;
                }
            }
        }


        while(!q.isEmpty()){
            int[] cell = q.poll();
            int row = cell[0];
            int col = cell[1];

            for(int[] dir : directions){
                int newRow = row + dir[0];
                int newCol = col + dir[1];

                if((newRow >= 0 && newRow < n) && (newCol >= 0 && newCol < m) && mat[newRow][newCol] > mat[row][col] + 1){
                    mat[newRow][newCol] = mat[row][col] + 1;
                    q.add(new int[]{newRow, newCol});
                }
            }
        }

        return mat;
    }
}