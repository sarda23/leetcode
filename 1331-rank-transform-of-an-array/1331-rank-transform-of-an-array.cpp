class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        set<int> freq(begin(arr),end(arr)); // to keep element in sorted fashion
        unordered_map<int,int> mp; 
        int rank = 1;
        for(auto &num:freq){
            mp[num] = rank++; // to give the rank 
        }
       
        for(int i =0;i<arr.size();++i){
            arr[i] = mp[arr[i]];
        }
        return arr;
    }
};