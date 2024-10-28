class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        // without sorting
        unordered_set<int> st(begin(nums),end(nums));
        int n = nums.size();
        int maxStreak = 0;

        for(int i=0;i<n;++i){
            int streak = 0;
            long long curr = nums[i];

            while(st.find(curr) != st.end()){
                streak++;
                if(curr*curr >1e5){ // this can be interesting in interview discussion - if they give you the constraint - this while loop will only run for at most 5 time (2 4 16 256 65536 .... ) so overall the T.C - O(n) 
                    break;
                }
                curr = curr*curr;
            }
            maxStreak = max(maxStreak,streak);
        }
        return maxStreak<2?-1:maxStreak;

        // with sorting 
    //    unordered_map<int,int> mp;

    //    sort(begin(nums),end(nums));

    //    int maxStreak = 0;

    //    for(int &num:nums){
    //     // check if this number is a perfect square
    //     int root = (int)sqrt(num);

    //     if(root*root == num && mp.find(root) != mp.end()){
    //         mp[num] = mp[root] + 1;
    //     }else{
    //         mp[num] = 1;
    //     }
    //     maxStreak = max(maxStreak,mp[num]);
    //    } 

    //    return maxStreak<2 ? -1 : maxStreak;
    }
};