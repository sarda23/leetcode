class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        //Current Segment
        int numOfSetBits = __builtin_popcount(nums[0]);
        int maxOfSegment = nums[0];
        int minOfSegment = nums[0];

        int maxOfPrevSegment = INT_MIN;

        for (int i = 1; i < nums.size(); i++) {
            if (__builtin_popcount(nums[i]) == numOfSetBits) { //they belong to same segment
                maxOfSegment = max(maxOfSegment, nums[i]); //find max of current segment
                minOfSegment = min(minOfSegment, nums[i]); //find min of current segment
            } else {  // Element belongs to a new segment
                
                if (minOfSegment < maxOfPrevSegment) { //ye bataya hai maine video me
                    return false;
                }

                // Update the previous segment's max
                maxOfPrevSegment = maxOfSegment;

                // new segment started now
                maxOfSegment = nums[i];
                minOfSegment = nums[i];
                numOfSetBits = __builtin_popcount(nums[i]);
            }
        }
        // Final check for proper segment arrangement
        if (minOfSegment < maxOfPrevSegment) {
            return false;
        }
        return true;
    }
};