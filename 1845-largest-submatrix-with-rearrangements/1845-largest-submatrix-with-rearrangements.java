class Solution {
    public int largestSubmatrix(int[][] matrix) {
        int row = matrix.length;
        int col = matrix[0].length;

        // Calculate heights for each column
        for (int i = 1; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (matrix[i][j] == 1) {
                    matrix[i][j] += matrix[i - 1][j];
                }
            }
        }

        int res = 0;
        for (int i = 0; i < row; i++) {
            // Sort the heights in ascending order
            Arrays.sort(matrix[i]);

            // Iterate through the sorted heights
            for (int j = 0; j < col; j++) {
                int height = matrix[i][j];
                int width = col - j;
                res = Math.max(res, height * width);
            }
        }

        return res;        
    }
}


/*
class Solution {
    public int largestSubmatrix(int[][] matrix) {
        int n = matrix.length;
        int m = matrix[0].length;
        int ans= 0;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(matrix[i][j] != 0 && i > 0){
                    matrix[i][j] += matrix[i-1][j];
                }
            }

            // Convert row to Integer[] and sort in descending order
            Integer[] currCol = Arrays.stream(matrix[i])  // Convert int[] to Integer[]
                                     .boxed()
                                     .toArray(Integer[]::new);
            Arrays.sort(currCol, Collections.reverseOrder());  // Sort in descending order


            for(int j = 0; j < m; j++){
                int area = currCol[j] * (j+1);
                ans = Math.max(ans, area);
            }
        }

        return ans;
    }
}
*/