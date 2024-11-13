class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        int n = nums.size();

        sort(begin(nums),end(nums)); // O(nlog(n))

        long long result = 0;

        for(int i=0;i<n;i++){ // O(n* log(n))
             
            int idx = lower_bound(begin(nums) + i + 1, end(nums), lower-nums[i]) - begin(nums); // gives the first element NOT LESS than (lower - nums[i])
            
            int x = idx - 1 - i; // total number of elements

            idx = upper_bound(begin(nums) + i + 1, end(nums), upper-nums[i]) - begin(nums); // gives the first element Greater than (upper - nums[i])

            int y = idx - 1 - i; 

            result += (y-x);
        }

        return result;
    }
};