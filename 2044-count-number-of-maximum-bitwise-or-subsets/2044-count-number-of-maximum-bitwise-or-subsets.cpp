class Solution {
public:
    int count_subset(int idx,int curr_or,vector<int> &nums,int max_or,vector<vector<int>> &t){
        if(idx == nums.size()){
            if(curr_or == max_or){
                return 1; // found one subset
            }
            return 0;
        }
        if(t[idx][curr_or] != -1){
            return t[idx][curr_or];
        }
        // take nums[idx]
        int take_count = count_subset(idx+1,curr_or | nums[idx], nums,max_or,t);

        // not take nums[idx]
        int not_take_count = count_subset(idx+1,curr_or,nums,max_or,t);

        return t[idx][curr_or] = take_count + not_take_count;
    }

    int countMaxOrSubsets(vector<int>& nums) {
        int max_or = 0;
        for(int &num:nums){
            max_or |= num;
        }
        int n = nums.size();

        vector<vector<int>> t(n+1,vector<int>(max_or+1,-1));
        int curr_or = 0;
        return count_subset(0,curr_or,nums,max_or,t);
    }
};