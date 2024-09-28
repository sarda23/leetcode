// can use some data structure  -  here using vector
class MyCircularDeque {
public:
    int K; // total capacity
    vector<int>deq;
    int front;
    int last;
    int current_count;
    // initialize
    MyCircularDeque(int k) {
        K = k;
        deq = vector<int>(K,0);
        front = 0;
        last = K-1;
        current_count = 0;    
    }
    
    bool insertFront(int value) {
        if(isFull()){
            return false;
        }

        front = (front - 1 + K) %K;
        deq[front] = value;
        current_count++;
        return true;
    }
    
    bool insertLast(int value) {
        if(isFull()){
            return false;
        }

        last = (last + 1)%K;
        deq[last] = value;
        current_count++;
        return true;
    }
    
    bool deleteFront() {
        if(isEmpty()){
            return false;
        }
        // only updating the pointer is sufficient
        front = (front+1)%K;
        current_count--;
        return true;
    }
    
    bool deleteLast() {
        if(isEmpty()){
            return false;
        }

        last = (last - 1 + K)% K;
        current_count--;
        return true;
    }
    
    int getFront() {
        if(isEmpty()){
            return -1;
        }
        return deq[front];
    }
    
    int getRear() {
        if(isEmpty()){
            return -1;
        }
        return deq[last];
    }
    
    bool isEmpty() {
        return current_count == 0;
    }
    
    bool isFull() {
        return current_count == K;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */