class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int n = nums.size();

        vector<int> result(n);

        // step-1 find the total XOR
        int XOR = 0;
        for(int i=0;i<n;i++){
            XOR ^= nums[i];
        }

        // to find flip, first find the mask having all bits set to 1
        int mask = (1<<maximumBit) - 1; // 2^maximumBit-1

        for(int i =0;i<n;i++){
            int k = XOR^mask; // this will give me the flipped value of XOR that is my best k
            result[i] = k;

            // right most element ko remove karna hai
            XOR ^= nums[n-i-1]; // last element hat jayega  a^a = 0 toh last element ko xor karte jao woh hatte jayega
        }

        return result;
    }
};