class Solution {
    public int mostBooked(int n, int[][] meetings) {
        var meetingCount = new int[n];
        var usedRooms = new PriorityQueue<long[]>((a, b) -> a[0] != b[0] ? Long.compare(a[0], b[0]) : Long.compare(a[1], b[1]));
        var unusedRooms = new PriorityQueue<Integer>();

        for (int i = 0; i < n; i++) {
            unusedRooms.offer(i);
        }

        Arrays.sort(meetings, (a, b) -> a[0] != b[0] ? Integer.compare(a[0], b[0]) : Integer.compare(a[1], b[1]));

        for (int[] meeting : meetings) {
            int start = meeting[0], end = meeting[1];

            while (!usedRooms.isEmpty() && usedRooms.peek()[0] <= start) {
                int room = (int) usedRooms.poll()[1];
                unusedRooms.offer(room);
            }

            if (!unusedRooms.isEmpty()) {
                int room = unusedRooms.poll();
                usedRooms.offer(new long[]{end, room});
                meetingCount[room]++;
            } else {
                long roomAvailabilityTime = usedRooms.peek()[0];
                int room = (int) usedRooms.poll()[1];
                usedRooms.offer(new long[]{roomAvailabilityTime + end - start, room});
                meetingCount[room]++;
            }
        }

        int maxMeetingCount = 0, maxMeetingCountRoom = 0;
        for (int i = 0; i < n; i++) {
            if (meetingCount[i] > maxMeetingCount) {
                maxMeetingCount = meetingCount[i];
                maxMeetingCountRoom = i;
            }
        }

        return maxMeetingCountRoom;
    }
}


/*
class Solution {
    public int mostBooked(int n, int[][] meetings) {
        // Sort the meetings based on start time
        Arrays.sort(meetings, (a, b) -> Integer.compare(a[0], b[0]));

        // Min-heap for busy rooms: [end_time, room_index]
        PriorityQueue<int[]> busyRooms = new PriorityQueue<>((a, b) -> {
            if (a[0] != b[0]) return Integer.compare(a[0], b[0]);
            return Integer.compare(a[1], b[1]);
        });

        // Min-heap for idle rooms, sorted by room index
        PriorityQueue<Integer> idleRooms = new PriorityQueue<>();
        for (int i = 0; i < n; i++) {
            idleRooms.add(i);
        }

        // Array to track the frequency of usage for each room
        int[] roomFrequency = new int[n];

        for (int[] meeting : meetings) {
            int start = meeting[0];
            int end = meeting[1];

            // Free up rooms that are no longer busy
            while (!busyRooms.isEmpty() && busyRooms.peek()[0] <= start) {
                idleRooms.add(busyRooms.poll()[1]);
            }

            if (!idleRooms.isEmpty()) {
                // If there's an available room, assign the meeting to the smallest-indexed room
                int room = idleRooms.poll();
                roomFrequency[room]++;
                busyRooms.add(new int[]{end, room});
            } else {
                // If no room is available, wait for the earliest available room
                int[] earliestRoom = busyRooms.poll();
                int room = earliestRoom[1];
                roomFrequency[room]++;
                // Schedule the meeting in this room after it becomes available
                busyRooms.add(new int[]{earliestRoom[0] + (end - start), room});
            }
        }

        // Find the room with the maximum usage, and if there's a tie, the smallest index
        int maxRoom = 0;
        for (int i = 1; i < n; i++) {
            if (roomFrequency[i] > roomFrequency[maxRoom] || 
                (roomFrequency[i] == roomFrequency[maxRoom] && i < maxRoom)) {
                maxRoom = i;
            }
        }

        return maxRoom;
    }
}

*/