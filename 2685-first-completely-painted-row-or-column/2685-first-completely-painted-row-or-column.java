class Solution {
    public int firstCompleteIndex(int[] arr, int[][] mat) {
        int n = mat.length;
        int m = mat[0].length;

        // Map each number in mat to its position (row, col)
        Map<Integer, int[]> numToPos = new HashMap<>();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                numToPos.put(mat[i][j], new int[]{i, j});
            }
        }

        // Track the count of negative numbers in each row and column
        int[] rowCount = new int[n];
        int[] colCount = new int[m];

        // Process each number in arr
        for (int i = 0; i < arr.length; i++) {
            int num = arr[i];
            int[] pos = numToPos.get(num); // Get position of the number
            int row = pos[0], col = pos[1];

            // Mark the cell as "processed"
            mat[row][col] = -mat[row][col];

            // Increment the count of negatives in the corresponding row and column
            rowCount[row]++;
            colCount[col]++;

            // Check if the current row or column is complete
            if (rowCount[row] == m || colCount[col] == n) {
                return i; // Return the index of the first complete row or column
            }
        }

        return -1; // No complete row or column was found
    }
}



/*
class Solution {
    public int firstCompleteIndex(int[] arr, int[][] mat) {
        int nR = mat.length;
        int mC = mat[0].length;

        Map<Integer, Pair<Integer, Integer>> mpToPos = new HashMap<>();

        for(int i = 0; i < nR; i++){
            for(int j = 0; j < mC; j++){
                int val = mat[i][j];
                mpToPos.put(val, new Pair(i,j));
            }
        }

        // Track the count of negative numbers in each row and column
        int[] rowCount = new int[nR];
        int[] colCount = new int[mC];


        for(int i =0; i < arr.length; i++){
            int num = arr[i];
            Pair<Integer, Integer> pos = mpToPos.get(num);
            int row = pos.getKey();
            int col = pos.getValue();

            mat[row][col] -= mat[row][col];

            rowCount[row]++;
            colCount[col]++;

            if(rowCount[row] == mC || colCount[col] == nR){
                return i;
            }
        }

        return -1;
    }
}
*/