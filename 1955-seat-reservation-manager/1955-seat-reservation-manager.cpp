class SeatManager {
    priority_queue<int, vector<int>, greater<int>> availableSeats;
public:
    SeatManager(int n) {
        for(int seatNum = 1; seatNum <= n; seatNum++){
            availableSeats.push(seatNum);
        }
    }
    
    int reserve() {
        int seatNumr = availableSeats.top();
        availableSeats.pop();
        return seatNumr;
    }
    
    void unreserve(int seatNumber) {
        availableSeats.push(seatNumber);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */