class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();

        deque<int> deq; // monotonic increasing order of cumulative sum
        vector<long long> cum_sum(n,0); // this stores the cumulative sum

        int res = INT_MAX;
        int j = 0;

        while(j<n){
            if(j == 0){
                cum_sum[j] = nums[j];
            }
            else{
                cum_sum[j] = cum_sum[j-1] + nums[j];
            }
            if(cum_sum[j] >= k){
                res = min(res,j+1);
            }

            // need to shrink the window or not
            while(!deq.empty() && cum_sum[j] - cum_sum[deq.front()] >= k){
                res = min(res,j-deq.front());
                deq.pop_front();
            }

            while(!deq.empty() && cum_sum[j] <= cum_sum[deq.back()]){
                deq.pop_back();
            }

            deq.push_back(j);
            j++;
        }       

        return res==INT_MAX?-1:res; 
    }
};