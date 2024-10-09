class Solution {
public:
    int minAddToMakeValid(string s) {
       int close = 0;
       int open  = 0;

       for(char &ch:s){
        // agar open aa raha hai toh open badao and agar close aaya toh check kar lo open hai kya - open hua toh balance tha toh pop kar lo matlab open-- and agar nahi tha matlab close extra hai toh close ko bada lo
        if(ch == '('){
            open++;  
        } 
        else if(open != 0){
            open--;
        }
        else{
            close++;
        }
       }
       return open+close; 
    }
};