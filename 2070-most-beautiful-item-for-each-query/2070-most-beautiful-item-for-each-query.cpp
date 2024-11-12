class Solution {
public:

    int binary_search(vector<vector<int>>& items,int query_price){
        int l = 0;
        int r = items.size()-1;

        int mid;
        int max_beauty = 0;

        while(l <= r){

            mid = l + (r-l)/2;

            if(items[mid][0] > query_price){
                r = mid-1; // ignore current and right side items
            }
            else{
                max_beauty = max(max_beauty,items[mid][1]);
                l = mid+1; // go to right side
            }
        }
        return max_beauty;
    }

    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
       int n = items.size();
       int m = queries.size();

       vector<int> result(m);

       // step-1: sort the array based on price in ascending order
       sort(begin(items),end(items)); // {price, beauty} by default sort by price

       int max_beauty_seen = items[0][1];

       for(int i=1;i<n;i++){
            max_beauty_seen = max(max_beauty_seen, items[i][1]);
            items[i][1] = max_beauty_seen;
       }

       for(int i=0;i<m;i++){
            int query_price = queries[i];
            result[i] = binary_search(items,query_price);
       }
       return result;
    }
};