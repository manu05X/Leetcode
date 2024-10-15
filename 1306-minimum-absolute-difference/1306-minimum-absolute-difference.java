class Solution {
    public List<List<Integer>> minimumAbsDifference(int[] arr) {
        int n = arr.length;
 
        Arrays.sort(arr);

        int minAbsDiff = Integer.MAX_VALUE;
        for(int i = 1; i < n; i++){
            minAbsDiff = Math.min(minAbsDiff, arr[i]-arr[i-1]);
        }

        List<List<Integer>> ans = new ArrayList<>();

        for(int i =1; i < n; i++){
            if(arr[i]-arr[i-1] == minAbsDiff){
                ans.add(Arrays.asList(arr[i-1], arr[i]));
            }
        }

        return ans;
    }
}