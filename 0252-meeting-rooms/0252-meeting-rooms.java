class Solution {
    public boolean canAttendMeetings(int[][] intervals) {
        int n = intervals.length;
        Arrays.sort(intervals, (a,b)->Integer.compare(a[1], b[1]));
        if(n == 0){
            return true;
        }
        int prevEnd = intervals[0][1];

        for(int i = 1; i < n; i++){
            if(prevEnd > intervals[i][0]){
                return false;
            }
            prevEnd = intervals[i][1];
        }

        return true;
    }
}


// class Solution {
//     public boolean canAttendMeetings(int[][] intervals) {
//         int n = intervals.length;
//         Arrays.sort(intervals, (a,b)->Integer.compare(a[1], b[1]));
//         if(n == 0){
//             return true;
//         }

//         for(int i = 0; i < n-1; i++){
//             if(intervals[i][1] > intervals[i+1][0]){
//                 return false;
//             }
//         }

//         return true;
//     }
// }