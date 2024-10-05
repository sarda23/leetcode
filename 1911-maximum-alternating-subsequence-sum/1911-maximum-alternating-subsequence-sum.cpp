class Solution {
public:
    // typedef long long ll;
    // int n;
    // ll t[100001][2];
    // ll solve(int idx,vector<int> &nums,bool flag){
    //     if(idx >= n){
    //         return 0;
    //     }

    //     if(t[idx][flag] != -1){
    //         return t[idx][flag];
    //     }
    //     ll skip = solve(idx+1,nums,flag);
    //     ll val  = nums[idx];
    //     if(flag == false){
    //         val = -val;
    //     } 
    //     ll take = val + solve(idx+1,nums,!flag);

    //     return t[idx][flag]=max(skip,take);
    // }

    long long maxAlternatingSum(vector<int>& nums) {
        // bottom up
        int n = nums.size();

        vector<vector<long>> t(n+1,vector<long>(2,0)); // even:0 odd:1

        for(int i = 1;i<n+1;++i){
            // agar i ke lia 2 choice - ya toh woh aise subsequence me add ho jiska length even hojaye and 2 choice hai ki ya toh use le ya nahi 0 even 
            t[i][0] = max(t[i-1][1] - nums[i-1] /* take */ , 
                            t[i-1][0] /* skip */);
            // odd
            t[i][1] = max(t[i-1][0] + nums[i-1] , t[i-1][1]);
        }
        
        return max(t[n][0] , t[n][1]);
        // 1st approach 
        // n = nums.size();
        // memset(t,-1,sizeof(t));
        // return solve(0,nums,true);
    }
};