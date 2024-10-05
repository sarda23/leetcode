class Solution {
public:
    // int t[101];

    // int solve(vector<int> &nums,int i,int n){
    //     if(i>n){
    //         return 0;
    //     }
    //     if(t[i] != -1){
    //         return t[i];
    //     }

    //     int take = nums[i] + solve(nums,i+2,n);
    //     int skip = solve(nums,i+1,n);

    //     return t[i] = max(take , skip);
    // }

    int rob(vector<int>& nums) {
        int n = nums.size();

        if(n == 1){
            return nums[0];
        }

        if(n == 2){
            return max(nums[0] , nums[1]);
        }
        // 2nd approach
        vector<int> t(n+1,0);
        //t[i] -- money stolen when you have i houses

        t[0] = 0;

        //case 1  take 1st house hence skip the last house

        for(int i = 1;i<=n-1;++i){
            int skip = t[i-1];

            int take = nums[i-1] + ((i-2<0) ? 0 : t[i-2]);

            t[i] = max(skip,take);
        }
        int result_1 = t[n-1];

        t.clear();
        // case 2 - skip 1st house - u can take the last house
        t[0] = 0;
        t[1] = 0; // skip 1st house
        for(int i = 2;i<=n;++i){
            int skip = t[i-1];

            int take = nums[i-1] + ((i-2<0) ? 0 : t[i-2]);
            
            t[i] = max(skip,take);
        }
        int result_2 = t[n];

        return max(result_1,result_2);

        // 1st approach
        // memset(t,-1,sizeof(t));

        // // case 1 -- take 1st house - 0'th index wala house

        // int take_0th = solve(nums,0,n-2);

        // memset(t,-1,sizeof(t));

        // // case 2 -- take the 2nd house - 1st index wala house
        // int take_1st = solve(nums,1,n-1);

        // return max(take_0th,take_1st);
    }
};