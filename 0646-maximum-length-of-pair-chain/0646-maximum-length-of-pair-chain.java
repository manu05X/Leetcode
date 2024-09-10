class Solution {
    public int findLongestChain(int[][] pairs) {
        // Sort pairs based on the second element of each pair
        // Arrays.sort(pairs, new Comparator<int[]>() {
        //     @Override
        //     public int compare(int[] a, int[] b) {
        //         return Integer.compare(a[1], b[1]);
        //     }
        // });
         Arrays.sort(pairs, (a, b) -> a[1] - b[1]);

        int count = 1;
        int prev = pairs[0][1]; // Initialize with a very small value

        for (int i = 1; i < pairs.length; i++) {
            if (prev < pairs[i][0]) {
                count++;
                prev = pairs[i][1];
            }
        }

        return count;
    }
}