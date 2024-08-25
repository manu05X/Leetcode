class Solution {
    List<List<String>> res = new ArrayList<>();

    boolean isValidPosition(List<String> board, int row, int col){
        // Check vertically upwards for any other queens
        for(int i = row; i >= 0; i--){
            if(board.get(i).charAt(col) == 'Q'){
                return false; // Another queen found in the same column
            }
        }

        // Check the upper left diagonal
        for(int i = row, j = col; i >= 0 && j >= 0; i--,j--){
            if(board.get(i).charAt(j) == 'Q'){
                return false;
            }
        }

        // Check the upper right diagonal
        for(int i = row, j = col; i >= 0 && j < board.size(); i--,j++){
            if(board.get(i).charAt(j) == 'Q'){
                return false;
            }
        }

        return true;
    }

    public void dfs(List<String> board, int row){
        // If all rows have been filled, add the current board to the results
        if(row == board.size()){
            res.add(new ArrayList<>(board));
            return;
        }

        for(int i = 0; i < board.size(); i++){
             // Check if placing a queen at (row, i) is valid
            if(isValidPosition(board, row, i)){
                //board[row][i] = 'Q';  // Place the queen
                StringBuilder newRow = new StringBuilder(board.get(row));
                newRow.setCharAt(i, 'Q');  // Place the queen
                board.set(row, newRow.toString());
                dfs(board, row+1);  // Move on to the next row
                //board[row][i] = '.';  // Backtrack: remove the queen
                newRow.setCharAt(i, '.');  // Backtrack: remove the queen
                board.set(row, newRow.toString());
            }
        }

        return ;
    }

    public List<List<String>> solveNQueens(int n) {
        if(n < 0){
            return res;
        }
        // Initialize the board with '.' indicating empty spaces
        List<String> board = new ArrayList<>();
        for(int i = 0; i < n; i++){
            char[] row = new char[n];
            for(int j = 0; j < n; j++){
                row[j] = '.';
            }
            board.add(new String(row));
        }

        dfs(board, 0);
        return res;
    }
}