class Solution {
public:
    void rotate(vector<vector<int>>& mat) {
        int n = mat.size();
        for(int i = 0; i < n; i++)
        {
            for(int j = i+1; j < n; j++)
            {
                swap(mat[i][j],mat[j][i]);
            }
        }
        
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