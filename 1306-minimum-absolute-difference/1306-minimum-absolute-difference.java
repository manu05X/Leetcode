class Solution {
    public List<List<Integer>> minimumAbsDifference(int[] arr) {
        int n = arr.length;
        
        // Sort the array first
        Arrays.sort(arr);

        // Find the minimum absolute difference
        int minAbsDiff = Integer.MAX_VALUE;
        for (int i = 1; i < n; i++) {
            minAbsDiff = Math.min(minAbsDiff, arr[i] - arr[i-1]);
        }

        // Create the result list
        List<List<Integer>> ans = new ArrayList<>();

        // Add pairs with the minimum absolute difference
        for (int i = 1; i < n; i++) { // Start from i = 1 to avoid out-of-bounds
            if (arr[i] - arr[i-1] == minAbsDiff) {
                ans.add(Arrays.asList(arr[i-1], arr[i]));
            }
        }

        return ans;
    }
}
