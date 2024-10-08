class Solution {
public:
    int minSwaps(string s) {
        stack<char> st;

        for(char &ch:s){
            if(ch == '['){
                st.push(ch);
            }
            else if(!st.empty()){
                st.pop(); // balance closing bracket with an open bracket in the stack
            }
        }
        //size of stack = number of open bracket

        return (st.size() + 1)/2;
    }
};