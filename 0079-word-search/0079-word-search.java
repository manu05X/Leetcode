class Solution {
     private char[][] matrix;
    private int ROWS;
    private int COLS;
    public boolean exist(char[][] board, String word) {
        this.matrix = board;
        this.ROWS = board.length;
        this.COLS = board[0].length;

        for(int row = 0; row < ROWS; row++){
            for(int col = 0; col < COLS; col++){
                if(backtrack(word,row,col,0)) 
                    return true;
            }
        }

        return false;
    }

    protected boolean backtrack(String word, int row, int col, int start){
        /* Step 1). check the bottom case. */
        if(start >= word.length())
            return true;

        /* Step 2). Check the boundaries. */
        if(row < 0 || col < 0 || row >= ROWS || col >= COLS || this.matrix[row][col] != word.charAt(start)){
            return false;
        }

        //Step 3) mark the path before the next exploration
        this.matrix[row][col] = '*';
        int[] rowOffsets = { 0, 1, 0, -1 };
        int[] colOffsets = { 1, 0, -1, 0 };

        /* Step 4). explore the neighbors in DFS */
        for(int dir = 0; dir < 4; dir++){
            if(backtrack(word, row + rowOffsets[dir], col + colOffsets[dir], start+1)){
                // return without cleanup
                return true;
            }
        }
        /* Step 5). clean up and return the result. */
        this.matrix[row][col] = word.charAt(start);
        return false;

    }

}