// for optimization
// ordered set - insertion - O(logn)
    // search - Binary search use hota hai isme - O(logn) 
// or we can use ordered map
class MyCalendar {
public:

    set<pair<int,int>> st;  // space - number of event
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        //find the first event that starts after or at the same time of (start,end)
        //>=  - lower bound ki baat ho rahi hai
        auto it = st.lower_bound({start,end});//log(n)

        //check if the current event overlaps with the next event
        if(it != st.end() && it->first < end){
            return false;
        }

        // check if the current event overlaps with the previous event
        if(it != st.begin()){
            auto prevIt = prev(it);
            if(start < prevIt->second){
                return false;
            }
        }

        st.insert({start,end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */