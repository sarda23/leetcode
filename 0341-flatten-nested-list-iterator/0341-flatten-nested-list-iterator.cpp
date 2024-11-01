/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

// 3rd approach -
// the NestedIterator is only for initialization and hasNext and next are the function which are called multiple times so we can do most of the work during initialization 

class NestedIterator {
public:
    queue<int> q;

    void Flatten(vector<NestedInteger> &nestedList){
        int n = nestedList.size();

        for(int i =0;i<n;i++){
            NestedInteger& obj = nestedList[i];
            if(obj.isInteger()){
                q.push(obj.getInteger());
            }
            else{
                Flatten(obj.getList());
            }
        }
    }

    NestedIterator(vector<NestedInteger> &nestedList) {
       Flatten(nestedList);
    }
    
    int next() {
      int num = q.front();
      q.pop();
      return num;
    }
    
    bool hasNext() {
         if(q.empty()){
            return false;
         }
         return true;
    }
};

/*
// 2nd method 
// in stack no need to put all the objects instead we can put the address of objects
// to access pointer things   use  ->   instead of . operator

class NestedIterator {
public:
    stack<NestedInteger*> st;  // stack of address of object

    NestedIterator(vector<NestedInteger> &nestedList) {
        int n = nestedList.size();

        for(int i=n-1;i>=0;i--){ // it is a stack so from the back we need to push the element
            st.push(&nestedList[i]);  // to get the address
        }
    }
    
    int next() {
        int num = st.top()->getInteger();
        st.pop();

        return num;
    }
    
    bool hasNext() {
         if(st.empty()){
            return false;
        }

        while(!st.empty()){
            NestedInteger* curr = st.top();  // st.top karoge toh address milega toh pointer chahiye store karne ke lia
            if(curr->isInteger()){
                return true;
            }

            st.pop();
            vector<NestedInteger>& vec = curr->getList();
            for(int i=vec.size()-1;i>=0;i--){ // from the last element as this is a stack so need to push in that order
                st.push(&vec[i]);
            }
        }

        return false;
    }
};
*/


// 1st method
/*
class NestedIterator {
public:
    stack<NestedInteger> st;
    NestedIterator(vector<NestedInteger> &nestedList) {
        int n = nestedList.size();

        for(int i=n-1;i>=0;i--){ // it is a stack so from the back we need to push the element
            st.push(nestedList[i]);
        }
    }
    
    int next() {
        int num = st.top().getInteger();
        st.pop();

        return num;
    }
    
    bool hasNext() {
        if(st.empty()){
            return false;
        }

        while(!st.empty()){
            NestedInteger curr = st.top();
            if(curr.isInteger()){
                return true;
            }

            st.pop();
            vector<NestedInteger> vec = curr.getList();
            for(int i=vec.size()-1;i>=0;i--){ // from the last element as this is a stack so need to push in that order
                st.push(vec[i]);
            }
        }

        return false;
    }
};
*/


/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */