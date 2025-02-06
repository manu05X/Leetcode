class Solution {
    public int largestAltitude(int[] gain) {
        int n = gain.length;

        int ans = 0;

        ans = Math.max(ans, gain[0]);
        for(int i = 1; i < n; i++){
            gain[i] += gain[i-1];
            ans = Math.max(gain[i],ans);
        }

        return ans;
    }
}