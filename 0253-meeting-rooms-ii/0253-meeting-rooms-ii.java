class Solution {
    public int minMeetingRooms(int[][] intervals) {
        int n = intervals.length;
        Arrays.sort(intervals, (a,b)->Integer.compare(a[0],b[0]));

        PriorityQueue<Integer> minHeap = new PriorityQueue<>();

        minHeap.add(intervals[0][1]);

        for(int i = 1; i < n; i++){
            if(intervals[i][0] >= minHeap.peek()){
                minHeap.poll();
            }

            minHeap.add(intervals[i][1]);
        }

        return minHeap.size();
    }
}





// class Solution {
//     public int minMeetingRooms(int[][] intervals) {
//         int[] starts = new int[intervals.length];
//         int[] ends = new int[intervals.length];
//         for (int i = 0; i < intervals.length; i++) {
//             starts[i] = intervals[i][0];
//             ends[i] = intervals[i][1];
//         }
//         Arrays.sort(starts);
//         Arrays.sort(ends);
//         int rooms = 0, endsItr = 0;
//         for (int i = 0; i < starts.length; i++) {
//             if (starts[i] < ends[endsItr]) {
//                 rooms++;
//             } else {
//                 endsItr++;
//             }
//         }
//         return rooms;
//     }
// }