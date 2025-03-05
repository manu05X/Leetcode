class Solution {
    // DFS function to mark all 'O's connected to the boundary as '#'
    void dfs(char[][] board, int n, int m, int currRow, int currCol) {
        // Base case: If the current cell is out of bounds or is not 'O', return
        if (currRow < 0 || currRow >= n || currCol < 0 || currCol >= m || board[currRow][currCol] != 'O') {
            return;
        }

        // Mark the current cell as '#' (temporary marker for 'O's connected to the boundary)
        board[currRow][currCol] = '#';

        // Recursively visit all four neighboring cells (up, down, left, right)
        dfs(board, n, m, currRow - 1, currCol); // up
        dfs(board, n, m, currRow + 1, currCol); // down
        dfs(board, n, m, currRow, currCol + 1); // right
        dfs(board, n, m, currRow, currCol - 1); // left
    }

    public void solve(char[][] board) {
        int n = board.length;    // Number of rows in the board
        int m = board[0].length; // Number of columns in the board

        // Step 1: Traverse the first and last columns
        for (int r = 0; r < n; r++) {
            // Check the first column
            if (board[r][0] == 'O') {
                dfs(board, n, m, r, 0); // Mark all connected 'O's as '#'
            }
            // Check the last column
            if (board[r][m - 1] == 'O') {
                dfs(board, n, m, r, m - 1); // Mark all connected 'O's as '#'
            }
        }

        // Step 2: Traverse the first and last rows
        for (int c = 0; c < m; c++) {
            // Check the first row
            if (board[0][c] == 'O') {
                dfs(board, n, m, 0, c); // Mark all connected 'O's as '#'
            }
            // Check the last row
            if (board[n - 1][c] == 'O') {
                dfs(board, n, m, n - 1, c); // Mark all connected 'O's as '#'
            }
        }

        // Step 3: Traverse the entire board and flip remaining 'O's to 'X' and restore '#' to 'O'
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < m; c++) {
                if (board[r][c] == 'O') {
                    // If the cell is still 'O', it is surrounded by 'X', so flip it to 'X'
                    board[r][c] = 'X';
                }
                if (board[r][c] == '#') {
                    // If the cell is marked as '#', restore it to 'O' (it was connected to the boundary)
                    board[r][c] = 'O';
                }
            }
        }
    }
}