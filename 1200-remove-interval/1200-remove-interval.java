class Solution {
    public List<List<Integer>> removeInterval(int[][] intervals, int[] toBeRemoved) {
        int n = intervals.length;
        List<List<Integer>> ans = new ArrayList<>();
        int removeStart = toBeRemoved[0];
        int removeEnd = toBeRemoved[1];

        for(int i = 0; i < n; i++)
        {
            int start = intervals[i][0], end = intervals[i][1];

            if(start >= removeEnd || end <= removeStart)
            {
                ans.add(Arrays.asList(start, end));
            }
            else
            {
                if(start < removeStart){
                    ans.add(Arrays.asList(start, removeStart));
                }
                if(end > removeEnd){
                    ans.add(Arrays.asList(removeEnd, end));
                }
            }
        }

        return ans;
    }
}