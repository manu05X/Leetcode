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