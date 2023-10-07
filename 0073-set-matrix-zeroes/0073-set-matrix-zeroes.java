class Solution {
    public void setZeroes(int[][] matrix) {
        int n = matrix.length;
        int m = matrix[0].length;
        // for marking mat[0][0] == 0
        boolean col0 = false;

        for(int i =0; i < n; i++)
        {
            // checking if 0 is present in 0th column or not
            if(matrix[i][0] == 0)
                col0 = true;

            for(int j = 1; j < m; j++)
            {
                if(matrix[i][j] == 0)
                {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        // traversing in reverse direction
        for(int i = n-1; i >= 0; i--)
        {
            for(int j = m-1; j >= 1; j--)
            {
                if(matrix[i][0] == 0 || matrix[0][j] == 0)
                {
                    matrix[i][j] = 0;
                }
            }
            // putting 0 at matrix[0][0] if col0 is false
            if(col0 == true)
            {
                matrix[i][0] = 0;
            }
        }
    }
}