class Solution {
public:
    // A 2D vector to store all possible solutions (boards)
    vector<vector<string>> res;
    
    // Function to check if placing a queen at (row, col) is valid
    bool isValidPos(vector<string> &board, int row, int col){
        // Check vertically upwards for any other queens
        for(int i = row; i >= 0; i--) {
            if(board[i][col] == 'Q') {
                return false; // Another queen found in the same column
            }
        }

        // Check the upper left diagonal
        for(int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
            if(board[i][j] == 'Q') {
                return false; // Another queen found on the upper left diagonal
            }
        }

        // Check the upper right diagonal
        for(int i = row, j = col; i >= 0 && j < board.size(); i--, j++) {
            if(board[i][j] == 'Q') {
                return false; // Another queen found on the upper right diagonal
            }
        }

        // No conflicts found, so this position is valid for placing a queen
        return true;
    }

    // Depth-first search (DFS) function to explore all possible placements
    void dfs(vector<string>& board, int row){
        // If all rows have been filled, add the current board to the results
        if(row == board.size()){
            res.push_back(board);
            return;
        }

        // Try placing a queen in each column of the current row
        for(int i = 0; i < board.size(); i++){
            // Check if placing a queen at (row, i) is valid
            if(isValidPos(board, row, i)) {
                board[row][i] = 'Q';  // Place the queen
                dfs(board, row + 1);  // Move on to the next row
                board[row][i] = '.';  // Backtrack: remove the queen
            }
        }
        return; // Return to explore other possibilities
    }

    // Main function to solve the N-Queens problem
    vector<vector<string>> solveNQueens(int n) {
        // If n is invalid (less than 0), return an empty solution
        if(n < 0){
            return {{}};
        }

        // Initialize the board with '.' indicating empty spaces
        vector<string> board(n, string(n, '.'));

        // Start the DFS from the first row
        dfs(board, 0);

        // Return all valid board configurations
        return res;
    }
};
