class CustomStack {
public:
    vector<int> st;
    vector<int> increments;
    int n;
    
    CustomStack(int maxSize) {
        n = maxSize;    
    }
    
    void push(int x) {
        if(st.size() < n){
            st.push_back(x);
            increments.push_back(0); // no increment as of now
        }    
    }
    
    int pop() {
        if(st.size() == 0){ // stack empty hai
            return -1;
        }
        int idx = st.size() - 1; // st.back() -- index of top element
        if(idx > 0){
            increments[idx - 1] += increments[idx]; // lazy propagation
        }
        int top_val = st[idx] + increments[idx];
        st.pop_back();
        increments.pop_back();//

        return top_val;
    }
    
    void increment(int k, int val) {
        // NOTE: K's value can be greater than size of stack
        int idx = min(k, (int)st.size()) - 1;   // k is 1 based
        if(idx >= 0){
            increments[idx] += val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */