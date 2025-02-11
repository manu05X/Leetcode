class Solution {
    public int[] findDiagonalOrder(int[][] mat) {
        int n = mat.length;
        int m = mat[0].length;

        int totalDiagLength = n*m;

        int[] ans = new int[totalDiagLength];

        int colPtr = 0;
        int rowPtr = 0;

        for(int i = 0; i < totalDiagLength; i++){
            ans[i] = mat[rowPtr][colPtr];
            
            int cellSum = rowPtr + colPtr;
            // cellSum % 2 == 0 Go Up i.e if cellSum is even
            if(cellSum % 2 == 0){
                // corner case of last column
                if(colPtr == m-1){
                    rowPtr++;
                }
                // corner case of first row
                 else if(rowPtr == 0){
                    colPtr++;
                }
                // normal update to go up diagonally 
                else {
                    rowPtr--;
                    colPtr++;
                }
                
            }
            // Go Down i.e if cellSum is odd
            else {
                // corner case of last row
                if(rowPtr == n-1){
                    colPtr++;
                }
                // corner case of first col
                 else if(colPtr == 0){
                    rowPtr++;
                }
                // normal update to go down diagonally 
                else {
                    rowPtr++;
                    colPtr--;
                }

            }
        }

        return ans;
    }
}