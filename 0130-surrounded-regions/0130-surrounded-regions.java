class Solution {
    void dfs(char[][] board, int n, int m, int currRow, int currCol){
        if(currRow < 0 || currRow >= n || currCol < 0 || currCol >= m || board[currRow][currCol] != 'O'){
            return ;
        }

        board[currRow][currCol] = '#';
        dfs(board, n, m, currRow-1, currCol); // up
        dfs(board, n, m, currRow+1, currCol); // down
        dfs(board, n, m, currRow, currCol+1); // <- right
        dfs(board, n, m, currRow, currCol-1); // left ->
        
    }


    public void solve(char[][] board) {
        int n = board.length;
        int m = board[0].length;

        for(int r = 0; r < n; r++){
            if(board[r][0] == 'O'){
                dfs(board, n, m, r, 0);
            }

            if(board[r][m-1] == 'O'){
                dfs(board, n, m, r, m-1);
            }
        }


        for(int c = 0; c < m; c++){
            if(board[0][c] == 'O'){
                dfs(board, n, m, 0, c);
            }

            if(board[n-1][c] == 'O'){
                dfs(board, n, m, n-1, c);
            }
        }

        for(int r = 0; r < n; r++){
            for(int c = 0; c < m; c++){
                if(board[r][c] == 'O'){
                    board[r][c] = 'X';
                }

                if(board[r][c] == '#'){
                    board[r][c] = 'O';
                }
            }
        }
        
    }
}