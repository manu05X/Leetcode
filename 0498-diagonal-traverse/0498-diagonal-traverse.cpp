class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int row = mat.size();
        int col = mat[0].size();
        int gridLength = row*col;

        vector<int> sol(gridLength,0);
        int colPtr = 0, rowPtr = 0;

        for(int i = 0; i < gridLength; i++){
            sol[i] = mat[rowPtr][colPtr];
             // (curRow+curCol)%2 == 0 Go Up
            if((rowPtr+colPtr)%2 == 0){
                // corner case of last column
                if(colPtr == col-1){
                    rowPtr++;
                }
                // corner case of first row
                else if(rowPtr == 0){
                    colPtr++;
                }
                else{// normal update to go up diagonally
                    rowPtr--;
                    colPtr++;
                }
            }
            // Go Down
            else{
                 // corner case of last row
                if(rowPtr == row-1){
                    colPtr++;
                }
                // corner case of first col
                else if(colPtr == 0){
                    rowPtr++;
                }
                // normal update to go down diagonally
                else{
                    rowPtr++;
                    colPtr--;
                }
            }
        }

        return sol;
    }
};