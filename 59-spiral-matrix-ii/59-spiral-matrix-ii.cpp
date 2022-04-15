class Solution {
public:

    vector<vector<int>> generateMatrix(int n) {

        vector<vector<int>> result (n, vector<int>(n));
        int cnt = 1;
        for (int layer = 0; layer < (n + 1) / 2; layer++) {
            // direction 1 - traverse from left to right
            for (int ptr = layer; ptr < n - layer; ptr++) {
                result[layer][ptr] = cnt++;
            }
            // direction 2 - traverse from top to bottom
            for (int ptr = layer + 1; ptr < n - layer; ptr++) {
                result[ptr][n - layer - 1] = cnt++;
            }
            // direction 3 - traverse from right to left
            for (int ptr = n - layer - 2; ptr >= layer; ptr--) {
                result[n - layer - 1][ptr] = cnt++;
            }
            // direction 4 - traverse from bottom to top
            for (int ptr = n - layer - 2; ptr > layer; ptr--) {
                result[ptr][layer] = cnt++;
            }
        }

        return result;
    }
};
/*<--------------------------------------------------------------------------------------------------------------------------->*/
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int r1 = 0, r2 = n-1;
        int c1 = 0, c2 = n-1;
        int val = 0;
		
		// result matrix
        vector<vector<int>> v(n, vector<int> (n));
        while(r1 <= r2 && c1 <= c2)
        {
            // left to right (row will be fixed)
            for(int i = c1; i <= c2; ++i)
                v[r1][i] = ++val;
				
				// move down(col will be fixed)
            for(int i = r1+1; i <= r2; ++i)
                v[i][c2] = ++val;
				
            // move right to left
            // move  up
            if(r1 < r2 && c1 < c2)
            {
                // move right to left (row will be fixed)
                for(int i = c2-1; i>c1; --i)
                    v[r2][i] = ++val;
					
					// move up (col will be fixed)
					for(int i = r2; i>r1; --i) 
                    v[i][c1] = ++val;
            }
            ++r1;
            --r2;
            ++c1;
            --c2;
        }
        return v;
    }
};
