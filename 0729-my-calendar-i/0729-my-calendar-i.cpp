class MyCalendar {
public:
    vector<pair<int,int>> bookings;
    MyCalendar() {
        
    }
    
      bool check_overlap(int start1,int end1,int start2,int end2){
        return max(start1,start2) < min(end1,end2);
    }

    bool book(int start, int end) {
        for(pair<int,int> booking : bookings){
            if(check_overlap(booking.first,booking.second,start,end)){
                return false;
            }
        }
        bookings.push_back({start,end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */