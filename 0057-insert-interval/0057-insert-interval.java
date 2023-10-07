class Solution {
    public int[][] insert(int[][] intervals, int[] newInterval) {
        int n = intervals.length;
        ArrayList<int[]> ans = new ArrayList<>();

        for(int i = 0; i < n; i++){
            if(newInterval[0] > intervals[i][1]){
                ans.add(intervals[i]);
            }
            else if(newInterval[1] < intervals[i][0]){
                ans.add(newInterval);
                for(int j = i; j < n; j++){
                    ans.add(intervals[j]);
                }
                return ans.toArray(new int[ans.size()][]);
            }
            else
            {
                newInterval[0] = Math.min(newInterval[0],intervals[i][0]);
                newInterval[1] = Math.max(newInterval[1],intervals[i][1]);
            }
        }
        ans.add(newInterval);

        return ans.toArray(new int[ans.size()][]);

    }
}