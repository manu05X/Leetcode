class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        unordered_map<int, pair<int,int>> mpNumToPos;

        for(int i = 0; i < n; i++){
            for(int j = 0; j<m; j++){
                int val = mat[i][j];
                mpNumToPos[val] = {i,j};
            }
        }

        vector<int>rowCount(n,0);
        vector<int>colCount(m,0);

        for(int i = 0; i < arr.size(); i++){
            int num = arr[i];
            auto [row, col] = mpNumToPos[num];
            mat[row][col] = -mat[row][col];

            rowCount[row]++;
            colCount[col]++;

            if(rowCount[row] == m || colCount[col] == n){
                return i;
            }
        }

        return -1;
    }
};


/* TLE
class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        unordered_map<int, pair<int,int>> mpNumToPos;

        for(int i = 0; i < n; i++){
            for(int j = 0; j<m; j++){
                int val = mat[i][j];
                mpNumToPos[val] = {i,j};
            }
        }

        for(int i = 0; i < arr.size(); i++){
            int num = arr[i];
            auto [row, col] = mpNumToPos[num];
            mat[row][col] = -mat[row][col];

            if(chekRow(row, mat) || chekCol(col, mat)){
                return i;
            }
        }

        return -1;
    }

    bool chekRow(int row, vector<vector<int>>& mat){
        for(int col = 0; col < mat[0].size(); col++){
            if(mat[row][col] > 0){
                return false;
            }
        }
        return true;
    }


    bool chekCol(int col, vector<vector<int>>& mat){
        for(int row = 0; row < mat.size(); row++){
            if(mat[row][col] > 0){
                return false;
            }
        }
        return true;
    }
};

*/