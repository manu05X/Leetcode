class Solution {
    public int largestUniqueNumber(int[] nums) {
        short[] count = new short[1001];

        for (int x : nums) {
            count[x]++;
        }

        for (int i = 1000 ; i >= 0; i --) {
            if(count[i] == 1) {
                return i;
            }
        }

        return -1;
    }
}