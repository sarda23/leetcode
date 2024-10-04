class Solution {
public:
    //2nd approach
    // int solve(int n,vector<int> &dp){
    //     if(n<=1){
    //         return n;
    //     }

    //     if(dp[n] != -1){
    //         return dp[n];
    //     }

    //     return dp[n] = solve(n-1,dp) + solve(n-2,dp);
    // }
    int fib(int n) {
        // 3rd - bottom up
        if(n<=1){
            return n;
        }

        //vector<int> dp(n+1,-1);

        // dp[i] = ith fib num
        // dp[0] = 0;
        // dp[1] = 1;
        int a = 0;
        int b = 1;
        int c;

        for(int i=2;i<=n;++i){
            c = a + b;
            a = b;
            b = c;
        }

        return c;

        // 2nd approach
        // vector<int> dp(n+1,-1);

        // return solve(n,dp);
        
        // 1st approach
        // if(n <= 1){
        //     return n;
        // }

        // return fib(n-1) + fib(n-2);
    }
};