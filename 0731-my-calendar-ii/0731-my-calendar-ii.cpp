// store where double booking region happened
// check if double booking is created with existing bookings
class MyCalendarTwo {
public:

    vector<pair<int,int>> double_overlapped_region;
    vector<pair<int,int>> overall_booking;

    MyCalendarTwo() {
        
    }
    
    bool check_overlap(int start1,int end1,int start2,int end2){
        return max(start1,start2) < min(end1,end2);
    }

    pair<int,int> find_overlap_region(int start1,int end1,int start2,int end2){
        return {max(start1,start2),min(end1,end2)};
    }

    bool book(int start, int end) {
        // check if triple booking is created or not

        for(pair<int,int> region:double_overlapped_region){
            if (check_overlap(region.first,region.second,start,end)){
                return false; // triple booking
            }
        }    

        // check if it is creating double booking
        for(pair<int,int> booking : overall_booking){
            if(check_overlap(booking.first,booking.second,start,end)){
                double_overlapped_region.push_back(find_overlap_region(booking.first,booking.second,start,end));
            }
        }

        overall_booking.push_back({start,end});
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */