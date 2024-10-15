class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        long long sum = 0;

        priority_queue<int> pq(begin(nums),end(nums)); // Heapify O(n)

        while(k--){
            int maxE = pq.top();
            pq.pop();

            sum += maxE;

            maxE = ceil(maxE/3.0);

            pq.push(maxE);
        }

        return sum;

    }
};