class Solution {
    public int[][] insert(int[][] intervals, int[] newInterval) {
        int n = intervals.length;
        // Initialize an ArrayList to hold the merged intervals
        ArrayList<int[]> ans = new ArrayList<>();
        // Loop through the input intervals
        for(int i = 0; i < n; i++){
            // If the current interval starts before the new interval, add it to the answer list
            if(newInterval[0] > intervals[i][1]){
                //no Overlapping Case
                ans.add(intervals[i]);
            }
            // If the current interval starts after the new interval
            //no Overlapping Case
            else if(newInterval[1] < intervals[i][0]){
                // add it to the answer list
                ans.add(newInterval);
                for(int j = i; j < n; j++){
                    // Loop through the remaining intervals in the input array and add it to ans list
                    ans.add(intervals[j]);
                }
                // Convert the ArrayList to a 2D int array and return it
                return ans.toArray(new int[ans.size()][]);
            }
            // if the newInterval overlap the current intervals
            //Overlapping Case
            else
            {
                newInterval[0] = Math.min(newInterval[0],intervals[i][0]);
                newInterval[1] = Math.max(newInterval[1],intervals[i][1]);
            }
        }
        //if only newInterval is present and intervals array is empty
        ans.add(newInterval);
        // Convert the ArrayList to a 2D int array and return it
        return ans.toArray(new int[ans.size()][]);

    }
}