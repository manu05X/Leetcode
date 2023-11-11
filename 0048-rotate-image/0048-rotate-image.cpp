class Solution {
public:
    void rotate(vector<vector<int>>& mat) {
        int n = mat.size();

        //Diagnol swap
        for(int i = 0; i < n; i++)
        {
            for(int j = i+1; j < n; j++)
            {
                swap(mat[i][j],mat[j][i]);
            }
        }
        
        //each row reverse
        for(int i =0; i < n; i++)
        {
            int l = 0;
            int h = n-1;
            
            while(l < h)
            {
                swap(mat[i][l],mat[i][h]);
                l++;
                h--;
            }
        }
    }
};
/*
0. 1. 2
[1,2,3] 0
[4,5,6] 1 
[7,8,9] 2

  |
  V
  
1,4,7
2,5,8
3,6,9

*/
