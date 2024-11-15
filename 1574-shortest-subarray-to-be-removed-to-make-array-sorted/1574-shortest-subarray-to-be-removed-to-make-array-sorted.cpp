class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        // we can take 2 pointer - one from start and from end so that we know from the back of array how many elements are sorted

        int n = arr.size();
        // 6 3 10 11 15 20 13 3 18 12
        int i =0;
        int j =n-1;

        while(j>0 && arr[j] >= arr[j-1]){
            j--;
        }

        int ans = j; // important -this solve the edge cases - if it is already sorted

        while(i<j && (i==0 || arr[i]>=arr[i-1])){
            
            while(j<n && arr[i] > arr[j]){
                j++;
            }

            ans = min(ans,j-i-1);
            i++;
        }
        return ans;
    }
};