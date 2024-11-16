class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        std::ios::sync_with_stdio(0); 
        std::cin.tie(0);
        
        int m = meetings.size();
        // Min-heap for busy rooms, sorted by ending time.
        priority_queue<pair<long long,int> ,vector<pair<long long,int>>, greater<pair<long long,int>>> bussyRoom;
        // Min-heap for idle rooms, sorted by room index.
        priority_queue<int, vector<int>, greater<int>> unusedRoom;

         /* Sort the meetings based on start_time */
        sort(meetings.begin(), meetings.end(), [](vector<int>& a,vector<int>& b){
            return a[0]<b[0];
        });

        unordered_map<int, int> freq;
        /* Currently all the rooms are empty */
        for(int i = 0; i < n; i++){
            unusedRoom.push(i);
        }

        for(auto x : meetings)
        {
            int currStart = x[0];
            int currEnd = x[1];

            // Free up rooms that are no longer busy.
            //Move the meeting rooms in unusedRoom, with ending_time <= currStart, to unused 
            while(bussyRoom.size() > 0 && bussyRoom.top().first <= currStart){
                 pair<long long,int> topElement = bussyRoom.top();
                  bussyRoom.pop();
                int room = topElement.second;

                unusedRoom.push(room);
            }

            if(unusedRoom.size() > 0)
            { // If there is an available room, assign the meeting to the room with the smallest index.
                //if room is present ans unused
                int room = unusedRoom.top();
                unusedRoom.pop();

                // marking the frequency of room used
                freq[abs(room)] += 1;

                //Mark the room as bussyRoom
                bussyRoom.push({currEnd,room});

            }
            // if there are no rooms empty, wait for busssy room to be empty
            else{
                pair<long long,int> topElement = bussyRoom.top();
                bussyRoom.pop();

                //getting the roomNumber from topElement
                int room = topElement.second;
                // marking the frequency of room used
                freq[abs(room)] += 1;

                //Since duration has to be the same, the newEnd will be sum(end_time_of_the_prev_meeting, duration)
                long long newEnd = topElement.first;
                newEnd += (currEnd-currStart);

                //Mark the room as engaged
                bussyRoom.push({newEnd, room});
            }
        }

         /* Find the lowest room_number with maximum frequency */
        int maxi = 0;
        for(int i = 1; i < n; i++) {
            if(freq[i] > freq[maxi])
                maxi = i;
        }
        return maxi;
    }
};

/*

Input:
n = 3
meetings = [[1, 20], [2, 10], [3, 5], [4, 9], [6, 8]]
Output:
Room most booked: 1
__________________________________________________________________________
Step-by-Step Execution:
Initialization:
- Sort the meetings by start time: [[1, 20], [2, 10], [3, 5], [4, 9], [6, 8]]
- busyRoom = [] (Min-heap to track occupied rooms, sorted by end time)
- unusedRoom = [0, 1, 2] (Min-heap of available rooms, sorted by room index)
- freq = [0, 0, 0] (Array to track the frequency of usage for each room)

__________________________________________________________________________
Processing Each Meeting:

### Meeting [1, 20]:

- `currStart = 1`, `currEnd = 20`
- No rooms in `bussyRoom` to free.
- Room `0` (smallest in `unusedRoom`) is assigned.
- Update:
    - `freq = [1, 0, 0]`
    - `unusedRoom = [1, 2]`
    - `bussyRoom = [{20, 0}]`

__________________________________________________________________________
### Meeting [2, 10]:

- `currStart = 2`, `currEnd = 10`
- No rooms in `bussyRoom` to free.
- Room `1` is assigned (smallest index in unusedRoom).
- Update:
    - `freq = [1, 1, 0]`
    - `unusedRoom = [2]`
    - `bussyRoom = [{10, 1}, {20, 0}]`

__________________________________________________________________________
### Meeting [3, 5]:

- `currStart = 3`, `currEnd = 5`
- No rooms in `bussyRoom` to free up.
- Room `2` is assigned (smallest index in unusedRoom)..
- Update:
    - `freq = [1, 1, 1]`
    - `unusedRoom = []`
    - `bussyRoom = [{5, 2}, {20, 0}, {10, 1}]`

__________________________________________________________________________
### Meeting [4, 9]:

- `currStart = 4`, `currEnd = 9`
- if there are no rooms empty, wait for busssy room to be empty
    - `topElement = {5,2}`
    - `room = 2`
- Room `2` is freed (`endTime = 5`).
    - `bussyRoom = [{10, 1}, {20, 0}]`
    - `unusedRoom = [2]`
- Room `2` is reassigned for this meeting.
- `newEnd` = `5+(9-4) = 10`
- Update:
    - `freq = [1, 1, 2]`
    - `unusedRoom = []`
    - `bussyRoom = [{10, 1}, {20, 0}, {10, 2}]`

__________________________________________________________________________
### Meeting [6, 8]:

- `currStart = 6`, `currEnd = 8`
- Room `2`  and Room `1` is freed (`endTime = 10`).
- Free up Room 1 and Room 2 from busyRoom as their end = 10.
- Updates: busyRoom = [[20, 0]], unusedRoom = [1, 2]
- Assign Room 1 for this meeting (it has the smallest index among available rooms).

- if there are no rooms empty, wait for busssy room to be empty
    - `topElement = {10,1}`
    - `room = 1`
- But Room 1 is used 1
    - `bussyRoom = [{10, 2}, {20, 0}]`
    - `unusedRoom = [1]`
- Room 1 is reassigned for this meeting.
- `newEnd` = 10`+(8-6) = 12`
- Update:
    - `freq = [1, 2, 2]`
    - `unusedRoom = []`
    - `bussyRoom = [{10, 2}, {20, 0}, {12, 1}]`

__________________________________________________________________________
Final Updates:
Frequency of room usage: freq = [1, 2, 2]
Most booked room: Room 1 (it has the smallest index among rooms with the highest frequency).
Final Output:
Room most booked: 1
*/