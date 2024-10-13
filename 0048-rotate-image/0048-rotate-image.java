class Solution {
    public void rotate(int[][] matrix) {
        int n = matrix.length;
        int m = matrix[0].length;

        for(int i = 0; i < n; i++){
            for(int j = i+1; j < m; j++){
                int temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }


        for(int i = 0; i < n; i++){
            int l = 0;
            int h = m-1;

            while(l < h){
                int temp = matrix[i][l];
                matrix[i][l] = matrix[i][h];
                matrix[i][h] = temp;
                l++;
                h--;
            }
        }


    }
}

/*
r = i, c=j
matrix[r][c]

  c0,1,2
0->1,2,3
1->4,5,6
2->7,8,9
  |

c  0,1,2
0->1,4,7
1->2,5,8
2->3,6,9


matrix[0][1] = 2, matrix[1][0]
matrix[0][2] = 3
matrix[2][2] = 9


 */