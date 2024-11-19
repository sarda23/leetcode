class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();

        long long result = 0;
        long long curr_window = 0;

        unordered_set<int> st;

        int i =0,j=0;

        while(j<n){
            // check if nums[j] is already present in current window i--j

            while(st.count(nums[j])){
                curr_window -= nums[i];
                st.erase(nums[i]);
                i++;
            }

            curr_window += nums[j];
            st.insert(nums[j]);

            if(j-i+1 == k){
                result = max(result,curr_window);

                curr_window -= nums[i];
                st.erase(nums[i]);
                i++;
            }
            j++;
        }

        return result;
    }
};