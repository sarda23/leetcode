class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int sum = 0;
        int n = nums.size();
        // (a+b)%p = (a%p + b%p)%p
        for(int &num:nums){
            sum=(sum%p+num%p)%p;
        }
        int target = sum%p;

        if(target == 0){ // nothing to delete
            return 0; 
        }

        unordered_map<int,int> mp; // prev sum%p ko store karega
        int res = n;
        int curr = 0;
        mp[0] = -1;  // initial

        for(int j = 0;j<n;++j){
            curr = (curr + nums[j])%p;

            int rem = (curr - target + p)%p;
            if(mp.find(rem) != mp.end()){
                res = min(res, j - mp[rem]);
            }
            mp[curr] = j;
        }

        return res==n?-1:res;
    }
};