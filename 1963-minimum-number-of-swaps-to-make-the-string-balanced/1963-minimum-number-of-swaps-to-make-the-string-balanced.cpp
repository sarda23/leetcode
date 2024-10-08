class Solution {
public:
    int minSwaps(string s) {
        // stack<char> st;
        int size = 0;

        for(char &ch:s){
            if(ch == '['){
                // st.push(ch);
                size++;
            }
            else if(size > 0){
                //st.pop(); // balance closing bracket with an open bracket in the stack
                size--;
            }
        }
        //size of stack = number of open bracket
        return (size + 1)/2;
    }
};