class Solution {
    public int minMeetingRooms(int[][] intervals) {
        // Define the size for time slots (with assumed maximum time as 10^6+10)
        int n = 1000010; 
        int[] delta = new int[n]; // Array to hold the changes in ongoing meetings
      
        // Iterate through all intervals
        for (int[] interval : intervals) {
            // Increment the start time to indicate a new meeting starts
            ++delta[interval[0]]; 
            // Decrement the end time to indicate a meeting ends
            --delta[interval[1]]; 
        }
      
        // Initialize res to the first time slot to handle the case if only one meeting
        int res = delta[0];
      
        // Traverse over the delta array to find maximum number of ongoing meetings at any time
        for (int i = 1; i < n; ++i) {
            // Cumulate the changes to find active meetings at time i
            delta[i] += delta[i - 1];
            // Update res if the current time slot has more meetings than previously recorded
            res = Math.max(res, delta[i]);
        }
      
        // Return the maximum value found in delta, which is the minimum number of rooms required
        return res;
    }
}