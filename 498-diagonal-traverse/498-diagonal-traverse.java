class Solution {
    public int[] findDiagonalOrder(int[][] mat) {
        int row = mat.length;
        int col = mat[0].length;
        int totGrid = row*col;
        
        int sol[] = new int[totGrid];
        
        int curRow = 0, curCol = 0;
        for(int i = 0; i < sol.length; i++){
            sol[i] = mat[curRow][curCol];
            // (curRow+curCol)%2 == 0 Go Up
            if((curRow+curCol)%2 == 0)
            {
                // corner case of last column
                if(curCol == col - 1){
                    curRow++;
                }
                else if(curRow == 0){ // corner case of first row
                    curCol++;
                }
                else { // normal update to go up diagonally
                    curRow--;
                    curCol++;
                }
            } 
            else 
            { // Go Down
                // corner case of last row
                if(curRow == row-1){
                    curCol++;
                }
                else if(curCol == 0){ // corner case of first col
                    curRow++;
                }
                else{ // normal update to go down diagonally
                    curCol--;
                    curRow++;
                }
            }
        }
        
        return sol;
    }
}