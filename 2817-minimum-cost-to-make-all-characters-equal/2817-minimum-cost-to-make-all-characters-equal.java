class Solution {
    public long minimumCost(String s) {
        int n = s.length();
        long totalCost = 0;
        
        for (int i = 1; i < n; i++) {
            if (s.charAt(i) != s.charAt(i - 1)) {
                totalCost += Math.min(i, n - i); // Choose min flip cost
            }
        }
        
        return totalCost;
    }
}