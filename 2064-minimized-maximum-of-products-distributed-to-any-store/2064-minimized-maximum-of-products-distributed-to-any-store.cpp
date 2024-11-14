class Solution {
public:

    bool possible_to_distribute(int x,vector<int>& quantities,int shops){
        for(int &products : quantities){

            shops -= (products + x - 1)/x; // ceil(products/x) - an alternative way of ceil

            if(shops<0){
                return false;
            }
        }
        return true;
    }

    int minimizedMaximum(int n, vector<int>& quantities) {
        // binary search on ans 
        int m = quantities.size();

        int l = 1; // saare stores ko 1 1 product du
        int r = *max_element(begin(quantities),end(quantities));

        int result = 0;

        while(l<=r){
            int mid = l + (r-l)/2;

            // mann ke chal raha hu abhi ki mid hi x hai - itna distribute karne se hojayega

            if(possible_to_distribute(mid,quantities,n)){
                result = mid;
                r = mid - 1;
            }
            else{
                l = mid+1;
            }
        }

        return result;
    }
};