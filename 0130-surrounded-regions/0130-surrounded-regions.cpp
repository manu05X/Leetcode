class Solution {
public:
    void dfs(vector<vector<char>>& board, int m, int n, int i, int j){
        //edge case 
        if(i < 0 || j < 0 || i >= n || j >= m || board[i][j] != 'O')
        {
            return;
        }

        board[i][j] = '#';

        dfs(board,m,n,i-1,j); //up
        dfs(board,m,n,i+1,j); // down
        dfs(board,m,n,i,j-1); // <- west
        dfs(board,m,n,i,j+1); // east->

    }
    void solve(vector<vector<char>>& board) {
        int r = board.size();
        int c = board[0].size();

        //Moving to first and last column
        for(int i = 0; i < r; i++){
            if(board[i][0] == 'O'){
                dfs(board,c,r,i,0);
            }
            if(board[i][c-1] == 'O'){
                dfs(board,c,r,i,c-1);
            }
        }

        //Moving to first and last row
        for(int j = 0; j < c; j++){
            if(board[0][j] == 'O'){
                dfs(board,c,r,0,j);
            }
            if(board[r-1][j] == 'O'){
                dfs(board,c,r,r-1,j);
            }
        }

        //Now as our boundry O are marked with #, so if we find any # replace it with O and for rest of the case we can replace it with X
        for(int i = 0; i<r; i++){
            for(int j = 0; j < c; j++){
                if(board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
                if(board[i][j] == '#'){
                    board[i][j] = 'O';
                }
            }
        }
    }
};