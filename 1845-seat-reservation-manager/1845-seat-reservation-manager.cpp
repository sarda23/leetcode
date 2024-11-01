class SeatManager {
public:
    priority_queue<int,vector<int>,greater<int>> pq;
    int seatMarker; // smallest unerserved seat ko mark karke rekhega
    SeatManager(int n) {
        seatMarker = 1;
    }
    
    int reserve() {
        if(!pq.empty()){
            int seat = pq.top();
            pq.pop();
            return seat;
        }

        int seat = seatMarker; 
        seatMarker++;
        return seat;
    }
    
    void unreserve(int seatNumber) {
        pq.push(seatNumber);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */