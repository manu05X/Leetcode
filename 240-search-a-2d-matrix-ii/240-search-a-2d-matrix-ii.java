class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        int n = matrix.length;
        int m = matrix[0].length;
        
        for(int i = 0; i < n; i++)
        {
            for(int j = m-1; j >= 0; j--)
            {
                if(target > matrix[i][j])
                {
                    break;
                }
                if(target == matrix[i][j])
                {
                    return true;
                }
            }
        }
        return false;
    }
}