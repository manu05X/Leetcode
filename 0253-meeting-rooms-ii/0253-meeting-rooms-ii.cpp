class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<int> start;
        vector<int> end;

        // Separate the start and end times of the meetings
        for(int i = 0; i < n; i++){
            start.push_back(intervals[i][0]);
            end.push_back(intervals[i][1]);
        }

        // Sort both the start times and end times
        sort(start.begin(), start.end());
        sort(end.begin(), end.end());
        int room = 0;
        int endIdx = 0; // Pointer to track end times

        for(int startIdx = 0; startIdx < n; startIdx++){
            // If the current meeting starts before the earliest meeting ends, we need a new room
            if(start[startIdx] < end[endIdx]){
                room++;
            }
            else{
                // If the current meeting starts after or when the earliest meeting ends, reuse the room
                endIdx++;
            }
        }
        return room;
    }
};