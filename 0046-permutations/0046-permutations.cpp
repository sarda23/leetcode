class Solution {
public:
    int n;
    vector<vector<int>> result;
    // unordered_set<int> st;

    // void solve(vector<int> &temp, vector<int> &nums){

    //     if(temp.size() == n){
    //         result.push_back(temp);
    //         return;
    //     }

    //     for(int i = 0;i<n;++i){
    //         if(st.find(nums[i]) == st.end()){ // to avoid repetition
    //             temp.push_back(nums[i]);
    //             st.insert(nums[i]);
    //             solve(temp,nums);

    //             temp.pop_back();
    //             st.erase(nums[i]);
    //         }
    //     }
    // }

    void solve(int idx,vector<int> &nums){
        if(idx == n){
            result.push_back(nums);
            return;
        }

        for(int i=idx;i<n;++i){
            swap(nums[i],nums[idx]); // do
            solve(idx+1,nums); // explore
            swap(nums[i],nums[idx]); // undo
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        // n = nums.size();
        // vector<int> temp;

        // solve(temp,nums);

        // return result;    

        // 2nd approach

        n = nums.size();

        solve(0,nums);

        return result;
    }
};