class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_map<int,int> mp;
        int sum = 0;
        mp[0] = 1; // default case

        int result = 0;

        for(int i=0;i<n;++i){
            sum += nums[i];

            int rem = sum%k;
            if(rem < 0){
                rem += k;
            }

            if(mp.find(rem) != mp.end()){
                result += mp[rem];
            }

            mp[rem]++;
        }

        return result;


        
        // vector<int> cum_sum;
        // int sum=0,count=0;
        // for(int &num:nums){
        //     sum+=num;
        //     cum_sum.push_back(sum);
        // }
        // for(int i=0;i<nums.size();++i){
        //     for(int j=i;j<nums.size();++j){
        //         int t = i==0?cum_sum[j]:cum_sum[j]-cum_sum[i-1];
        //         if(t%k==0){
        //             count++;
        //         }
        //     }
        // }
        // return count;
    }
};