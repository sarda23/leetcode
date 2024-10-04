class Solution {
public:
    // int t[46];
    // int solve(int n){
    //     if(n<0){
    //         return 0;
    //     }
    //     if(t[n] != -1){
    //         return t[n];
    //     }

    //     if(n == 0){
    //         return 1; // we have got 1 way to cover all stairs
    //     }

    //     int one_step = solve(n-1);
    //     int two_step = solve(n-2);

    //     return t[n] = one_step + two_step;
    // }
    int climbStairs(int n) {
        //bottom up
        // array[i] -- no of ways to climb i stairs
        if(n == 1 || n == 2 || n == 3){
            return n;
        }

        int a = 1; // i-2
        int b = 2; // i-1
        int c = 3; // i
        // i ko nikal ne ke lia - u only need i-1 and i-2
        for(int i=3;i<=n;++i){
            c= b + a;
            a = b;
            b = c;
        }

        return c;

        // memset(t,-1,sizeof(t));
        // return solve(n);
    }
};