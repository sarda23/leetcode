class LRUCache {
public:
    list<int> dll; // key
    map<int,pair<list<int>::iterator, int>> mp;
    // address for node of DLL is denoted as - address type - list<int>::iterator  
    int n;

    LRUCache(int capacity) {
        n = capacity;
    }
    
    void make_recently_used(int key){
        dll.erase(mp[key].first);  // yeh key ko 1st delete karo
        // delete toh hogaya - ab usko fresh me dalna hai
        dll.push_front(key);

        mp[key].first = dll.begin(); // starting address toh dll.begin() hai
    }

    int get(int key) {
        if(mp.find(key) == mp.end()){
            return -1;
        }

        make_recently_used(key);

        return mp[key].second;
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()){
            mp[key].second = value;
            make_recently_used(key);
        }
        else{
            dll.push_front(key);
            mp[key] = {dll.begin() , value};
            n--;
        }
        // agar capacity se jada hojaye toh
        if(n<0){
            // key to be deleted
            int key_delete = dll.back();
            mp.erase(key_delete);
            dll.pop_back();

            n++;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */