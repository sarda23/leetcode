class Solution {
public:
    bool rotateString(string s, string goal) {
        // if we concatenate s+s - we can find if goal is substring 
        int m = s.length();
        int n = goal.length();

        if(m!=n){
            return false;
        }

        if((s+s).find(goal) != string::npos){
            return true;
        }

        return false;
        
        // Brute Force
        // if(s.length() != goal.length()){
        //     return false;
        // }
        // for(int i = 1;i<=s.length();i++){
        //     rotate(s.begin(),s.begin()+1,s.end());
        //     if(s == goal){
        //         return true;
        //     }
        // }
        // return false;
    }
};