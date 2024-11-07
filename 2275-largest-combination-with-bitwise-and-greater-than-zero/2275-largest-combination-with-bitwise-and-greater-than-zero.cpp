class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int ans = INT_MIN;
        // here by constraint only 24 bits are required so for loop can be run till 24
        for(int bitpos=0;bitpos<24;bitpos++){ // O(24)

            int count = 0;
            for(int &num:candidates){ // O(n)
                if((num & (1<<bitpos)) != 0){ // to find if the bit is set or not
                    count++;
                }
            }
            ans = max(ans,count);
        }
        return ans;
    }
};