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