class Solution {
public:
    int minChanges(string s) {
       int n = s.length();

       char ch = s[0];
       int count = 0;

       int changes = 0; // ans

       for(int i=0;i<n;i++){
        if(s[i] == ch){
            count++;
            continue;
        }

        // current character s[i] is not equal to ch (prev character)
        if(count%2 == 0){
            // previous substring is even
            count = 1;// start new substring
        }
        else{
            // s[i] ko change karna padega to make even substring length
            changes += 1;
            count = 0;
        }
        ch = s[i]; // update to new character
       } 

       return changes;
    }
};