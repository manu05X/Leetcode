class Solution {
    public int minMeetingRooms(int[][] intervals) {
        int n = intervals.length;
        // Sort the meetings by start time
        Arrays.sort(intervals, (a,b)->Integer.compare(a[0],b[0]));
        // Min-heap to track the end time of meetings
        PriorityQueue<Integer> minHeap = new PriorityQueue<>();
        // Add the end time of the first meeting
        minHeap.add(intervals[0][1]);

        // Iterate over the rest of the meetings
        for(int i = 1; i < n; i++){
            // If the room due to free up the earliest is free, remove it from the heap
            if(intervals[i][0] >= minHeap.peek()){
                minHeap.poll();
            }

            // Add the current meeting's end time to the heap
            minHeap.add(intervals[i][1]);
        }

        // The size of the heap is the number of rooms needed
        return minHeap.size();
    }
}

/*
i = 0 => pq = [30]
i = 1 => 5 > 30 false , pq = [10,30]
i = 2 => 15 > 10 true, i.e previous meeting end before curr start, so pop from top of minheap then insert curr endTime in the heap, pr = [20,30]

now interval end, so the size of hinHeap determine the no of room required

*/





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