class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int n = times.size();

        vector<int> chairs(n,-1);

        int targetFriendArrivalTime = times[targetFriend][0];

        sort(begin(times),end(times));
        
        for(vector<int> &t : times){
            int arr = t[0];
            int dpt = t[1];

            for(int i=0;i<n;++i){
                if(chairs[i] <= arr){
                    chairs[i] = dpt;
                
                    if(arr == targetFriendArrivalTime){
                        return i;
                    }
                    break;
                }
            }
        }
        return -1;
    }
};