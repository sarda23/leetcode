class Solution {
public:
    int n;
    vector<vector<int>> result;

    // void solve(unordered_map<int,int> &mp, vector<int> &temp){

    //     if(temp.size() == n){
    //         result.push_back(temp);
    //         return;
    //     }

    //     for(auto &[num,count] : mp){
    //         if(count== 0){ // u don't have num - nothing can be done
    //             continue;
    //         }

    //         temp.push_back(num); // do something
    //         mp[num]--;

    //         solve(mp,temp); // explore

    //         temp.pop_back(); // undo
    //         mp[num]++;
    //     }
    // }

    void solve(vector<int> &nums, int idx){
        
        if(idx == n){
            result.push_back(nums);
            return;
        }

        unordered_set<int> st; // this has to local not global - draw the tree  and see each level

        for(int i=idx;i<n;++i){ // try all possible i>=idx to swap with nums[idx]
             if(st.count(nums[i]) > 0) {
                continue;
            }
            
            st.insert(nums[i]);   // this has to be before swap 
            swap(nums[i],nums[idx]); // do something
            
            solve(nums,idx+1); // explore
            
            swap(nums[i],nums[idx]); // undo
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        n = nums.size();

        // unordered_map<int,int>mp;

        // for(int &num:nums){
        //     mp[num]++;
        // }
        
        // vector<int> temp;
        // solve(mp,temp);

        solve(nums,0);

        return result;
    }
};